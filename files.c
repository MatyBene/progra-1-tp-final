#include "files.h"
#include "validations.h"

int readUserFile (stUser *users, char *fileName)
{
    FILE * fi = fopen(fileName, "rb");

    int read = 0;

    if(fi)
    {
        while (fread(&users[read], sizeof(stUser), 1, fi) == 1)
        {
//            users[read].userId = read;
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

    if(fi)
    {
        for (int i = 0; i < totalUsers; i++)
        {

            printf("id %d ", users[i].userId);
            if (!isUserDeleted(users[i]))
            {
                printf("Se guarda\n");
                fwrite(&users[i], sizeof(stUser), 1, fi);
            }
            else
            {
                printf("No se guarda\n");
                appendUserFile(users, i, DELETED_USERS);
            }

        }

        fclose(fi);
    }
    else
    {
        printf("No se pudo abrir el archivo.");
    }
}

void appendUserFile (stUser *users, int id, char *fileName)
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

//int restoreUserFile (stUser *users, char *fileName, int id)
//{
//    stUser deletedUsers[100];
//    int totalDeletedUsers = readUserFile(deletedUsers, DELETED_USERS);
//
//    printAllUsers(deletedUsers, totalDeletedUsers);
//    printf("Ingrese el ID del usuario que desea restaurar. ")
//    deletedUsers[id].deleted = 0;
//
//}
