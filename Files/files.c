#include "files.h"
#include "../validations.h"

int readUserFile (stUser *users, char *fileName) // lee un archivo de usuarios, ordena el arreglo y retorna la cantidad de leidos
{
    FILE * fi = fopen(fileName, "rb");

    int read = 0;

    if(fi)
    {
        while (fread(&users[read], sizeof(stUser), 1, fi) == 1)
        {
            read++;
        }

        fclose(fi);

        qsort(users, read, sizeof(stUser), compareUserId); // funcion de ordenamiento rapido de C

        return read;
    }
    else
    {
        printf("No se pudo abrir el archivo.");
        return 0;
    }
}

void saveUserFile (stUser *users, char *fileName, int totalUsers) // guarda la totalidad del arreglo en el archivo especificado
{
    FILE * fi = fopen(fileName, "wb");


    if(fi)
    {
        for (int i = 0; i < totalUsers; i++)
        {
            fwrite(&users[i], sizeof(stUser), 1, fi);
        }

        fclose(fi);
    }
    else
    {
        printf("No se pudo abrir el archivo.");
    }
}

void deleteUserFile (stUser *users, int index, int totalUsers)     // elimina un usuario del archivo F_USERS y lo envia a F_DELETED_USERS
{
    FILE * fi = fopen(USERS, "wb");

    if(fi)
    {
        for (int i = 0; i < totalUsers; i++)
        {
            if (i != index)   // mientras un usuario no sea el eliminado eliminado lo guarda en F_USERS
            {
                fwrite(&users[i], sizeof(stUser), 1, fi);
            }
        }

        fclose(fi);
    }
    else
    {
        printf("No se pudo abrir el archivo.");
    }
}


void appendUserFile (stUser *users, char *fileName, int id) // agrega un usuario a un archivo sin eliminar lo existente
{
    FILE * fi = fopen(fileName, "ab");

    if(fi)
    {
        fwrite(&users[id], sizeof(stUser), 1, fi);

        fclose(fi);
    }
    else
    {
        printf("No se pudo abrir el archivo.");
    }
}


