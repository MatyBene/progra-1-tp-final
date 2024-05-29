#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

int menu(stUser *users, int index)
{

    int option;

    do
    {
        system("cls");
        printf("MENU PRINCIPAL\n\n");
        printf(" 0)  Cerrar sesion.\n");
        printf(" 1)  Perfil.\n");
        printf(" 2)  Editar informacion personal.\n");
        printf(" 3)  Salir.\n");
        if (users[index].isAdmin == 1)
        {
            printf(" ) Menu admin");
        }


        scanf("%d", &option);

        switch(option)
        {
            case 0:
            {
                system("cls");
                return 0;
            }
            case 1:
            {
                system("cls");
                printUser(users, index);
                system("pause");
                break;
            }
            case 2:
            {
                userInfo(users, index);
                break;
            }
        }
    }while (option != 0 && option != 3);

    return option;

}

int registerLogin(stUser *users, int *index)
{
    char option[9];
    int id = -1;

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

void adminMenu(stUser *users, int index, int *totalUsers)
{
    int option, id;
    char yn;

    do
    {
        system("cls");
        printf("MENU ADMIN\n\n");
        printf(" 0)  Cerrar sesion.\n");
        printf(" 1)  Ver usuarios registrados.\n");
        printf(" 2)  Eliminar usuario.\n");
        printf(" 3)  Ir al menu de usuario.\n");

        scanf("%d", &option);

        switch(option)
        {
            case 0:
            {
                system("cls");
                break;
            }
            case 1:
            {
                system("cls");
                printAllUsers(users, *totalUsers);
                system("pause");
                break;
            }
            case 2:
            {
                system("cls");
                printf("Seleccione el ID del usuario a eliminar: \n");
                scanf("%d", &id);
                do
                {
                    printf("Desea eliminar al usuario %s? (y/n)\n", users[id].username);
                    fflush(stdin);
                    yn = getch();
                    system("cls");
                }while(!yesNo(yn));

                if (yn == 'y' && users[id].isAdmin == 0)
                {
                    deleteUser(users, id, totalUsers);
                    printf("El usuario %d fue eliminado.\n", id);
                    system("pause");
                }
                else
                {
                    printf("No se elimino al usuario.\n", id);
                    system("pause");
                }
                break;
            }
            case 3:
            {
                system("cls");
                menu(users, index);
                system("pause");
                break;
            }
        }

    }while (option != 0);
}
