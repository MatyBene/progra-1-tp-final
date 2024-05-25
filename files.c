#include "files.h"

int countFile (char *fileName)
{
    FILE * fi = fopen(fileName, "rb");

    if (!fi)
    {
        printf("Error al abrir el archivo.\n");
        return 0;
    }

    char buffer[30];
    int i = 0;

    while (fgets(buffer, sizeof(buffer), fi))
    {
        i++;
    }

    fclose(fi);

    return i;
}

int readFile (stUser *users, char *fileName, size_t st)
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
