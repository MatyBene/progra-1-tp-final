#include "files.h"

int readUserFile (stUser *users, char *fileName, size_t st)
{
    FILE * fi = fopen(fileName, "rb");

    int read = 0;

    if(fi)
    {
        while (fread(&users[read], st, 1, fi) == 1)
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
