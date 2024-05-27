#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

void menu()
{
    stUser users[1000];

    printf("MENU DE ACCIONES");

//    userRegister(users, &totalUsers);

//    for(int i = 0; i < totalUsers; i++)
//    {
//        printUser(users, i);
//    }

//    userLogin(users, totalUsers);





}

void registerLogin(stUser *users, int *index)
{
    char opcion[9];

    printf(">>>>>>>>>>>>>>>BOOKET<<<<<<<<<<<<<<<<<<\n\n");
    printf("Ingrese la accion que desea realizar: (Registrar/Ingresar)\n");
    fflush(stdin);
    gets(opcion);

    if (strcmpi(opcion,"registrar") == 0)
    {
        userRegister(users, index);
    }
    else if (strcmpi(opcion,"ingresar") == 0)
    {
        userLogin(users, *index);
    }
    else
    {
        system("cls");
        printf("La opcion seleccionada no se reconoce. Intente nuevamente.\n");
    }

}
