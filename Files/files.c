#include "files.h"


int readFile (void *st, size_t stSize, char *fileName) // lee un archivo, ordena el arreglo y retorna la cantidad de leidos
{
    FILE * fi = fopen(fileName, "rb");

    int read = 0;

    if(fi)
    {
        while (fread((char*)st + (read * stSize), stSize, 1, fi) == 1)
        {
            read++;
        }

        fclose(fi);


        return read;
    }
    else
    {
        printf("No se pudo abrir el archivo.");
        return 0;
    }
}

void saveFile (void *st, size_t stSize, int totalElements, char *fileName) // guarda la totalidad del arreglo en el archivo especificado
{
//        qsort(st, read, sizeof(st[0]), compareUserId); // funcion de ordenamiento rapido de C

    FILE * fi = fopen(fileName, "wb");


    if(fi)
    {
        for (int i = 0; i < totalElements; i++)
        {
            fwrite((char*)st + (i * stSize), stSize, 1, fi);
        }

        fclose(fi);
    }
    else
    {
        printf("No se pudo abrir el archivo.");
    }
}

void deleteUserFile (stUser *users, char *fileName, int index, int totalUsers)     // elimina un usuario del archivo
{
    FILE * fi = fopen(fileName, "wb");

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


