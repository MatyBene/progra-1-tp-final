#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

void menu(stUser *users, int index)
{

    printUser(users, index);
//    userRegister(users, &totalUsers);

//    for(int i = 0; i < totalUsers; i++)
//    {
//        printUser(users, i);
//    }

//    userLogin(users, totalUsers);





}

int registerLogin(stUser *users, int *index)
{
    char opcion[9];
    int id = -1;

    printf(">>>>>>>>>>>>>>>BOOKET<<<<<<<<<<<<<<<<<<\n\n");

    while (strcmpi(opcion,"registrar") != 0 && strcmpi(opcion,"ingresar") != 0)
    {
        printf("Ingrese la accion que desea realizar: (Registrar/Ingresar)\n");
        fflush(stdin);
        gets(opcion);

        if (strcmpi(opcion,"registrar") == 0)
        {
            system("cls");
            id = userRegister(users, index);
        }
        else if (strcmpi(opcion,"ingresar") == 0)
        {
            system("cls");
            id = userLogin(users, *index);
        }
        else
        {
            system("cls");
            printf("La opcion seleccionada no se reconoce.\n");
        }
    }

    return id;

}
