#include "files.h"

int readUserFile (stUser *users, char *fileName)
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
        return read;

    }
    else
    {
        printf("No se pudo abrir el archivo.");
        return 0;
    }
}

void saveUserFile (stUser *users, char *fileName, int totalUsers)
{
    FILE * fi = fopen(fileName, "wb");

    int saved = 0;

    if(fi)
    {
        for (int i = 0; i < totalUsers; i++)
        {
            fwrite(&users[saved], sizeof(stUser), 1, fi);
            saved++;
        }

        fclose(fi);
    }
    else
    {
        printf("No se pudo abrir el archivo.");
    }
}
