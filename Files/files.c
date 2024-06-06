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

void saveFile (void *st, size_t stSize, int totalElements, char *fileName, int (*compare)(const void *, const void *)) // ordena y guarda la totalidad del arreglo en el archivo especificado
{
    qsort(st, totalElements, stSize, compare); // funcion de ordenamiento rapido de C

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

void deleteFile (void *st, size_t stSize, int index, int totalElements, char *fileName)     // elimina un elemento del archivo
{
    FILE * fi = fopen(fileName, "wb");

    if(fi)
    {
        for (int i = 0; i < totalElements; i++)
        {
            if (i != index)   // mientras un elemento no sea el eliminado lo guarda
            {
                fwrite((char*)st + (i * stSize), stSize, 1, fi);
            }
        }

        fclose(fi);
    }
    else
    {
        printf("No se pudo abrir el archivo.");
    }
}


void appendFile (void *st, size_t stSize, int index, char *fileName) // agrega un elemento a un archivo sin eliminar lo existente
{
    FILE * fi = fopen(fileName, "ab");

    if(fi)
    {
        fwrite((char*)st + (index * stSize), stSize, 1, fi);

        fclose(fi);
    }
    else
    {
        printf("No se pudo abrir el archivo.");
    }
}


