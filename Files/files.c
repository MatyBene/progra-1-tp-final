#include "files.h"

int readFile (void *st, size_t stSize, char *fileName) /// LEE UN ARCHIVO Y DEVUELVE LA CANTIDAD DE LEIDOS
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

void saveFile (void *st, size_t stSize, int totalElements, char *fileName, int (*compare)(const void *, const void *)) /// GUARDA UN ARREGLO DE ESTRUCTURAS EN UN ARCHIVO
{

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

void deleteFile (void *st, size_t stSize, int index, int totalElements, char *fileName)     /// ELIMINA UN ELEMENTO ESPECIFICADO DEL ARCHIVO
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


void appendFile (void *st, size_t stSize, int index, char *fileName) /// AGREGA UN ELEMENTO A UN ARCHIVO
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


