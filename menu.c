#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

int menu(stUser *users, int index)
{
//    if (users[index].isAdmin == 1)
//    {
//        menuAdmin();
//    }

    printf("0)  Cerrar sesion.");

    fflush(stdin);
    char option = getch();

    switch(option)
    {
        case 0:
        {
            printf("Se cerro la sesion de %s.\n", users[index]);
            return 0;
        }
    }




}

int registerLogin(stUser *users, int *index)
{
    char option[9];
    int id = -1;

    printf(">>>>>>>>>>>>>>>BOOKET<<<<<<<<<<<<<<<<<<\n\n");

    printf("Ingrese la accion que desea realizar: (Registrar/Ingresar)\n");
    fflush(stdin);
    gets(option);

    if (strcmpi(option,"registrar") == 0)
    {
        system("cls");
        id = userRegister(users, index);
    }
    else if (strcmpi(option,"ingresar") == 0)
    {
        system("cls");
        id = userLogin(users, *index);
    }
    else
    {
        system("cls");
        printf("La opcion seleccionada no se reconoce.\n");
        registerLogin(users, index);
    }


    return id;

}

void userInfo(stUser *users, int index)
{
    printUser(users, index);
}
