#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

char userMenu(stUser *users, int index)
{

    char option;


    do
    {
        system("cls");
        printf("MENU PRINCIPAL\n\n");
        printf("  0)  Cerrar sesion.\n");
        printf("  1)  Perfil.\n");
        printf("  2)  Editar informacion personal.\n");
        printf("esc)  Salir.\n");
        if (users[index].isAdmin == 1)
        {
            printf(" ) Menu admin");
        }

        fflush(stdin);
        option = getch();

        switch(option)
        {
            case '0':
            {
                system("cls");
                break;
            }
            case '1':
            {
                system("cls");
                printUser(users[index]);
                system("pause");
                break;
            }
            case '2':
            {
                userInfo(users, index);
                break;
            }
        }
    }while (option != '0' && option != 27);

    return option;

}


char adminMenu(stUser *users, int index, int *totalUsers)
{
    char option;

    do
    {
        system("cls");
        printf("MENU ADMIN\n\n");
        printf("  0)  Cerrar sesion.\n");
        printf("  1)  Ver usuarios registrados.\n");
        printf("  2)  Eliminar usuario.\n");
        printf("  3)  Restaurar usuario.\n");
        printf("  4)  Ir al menu de usuario.\n");
        printf("esc)  Salir.\n");

        fflush(stdin);
        option = getch();

        switch(option)
        {
            case '0':
            {
                system("cls");
                break;
            }
            case '1':
            {
                system("cls");
                printAllUsers(users, *totalUsers);
                system("pause");
                break;
            }
            case '2':
            {
                system("cls");
                deleteUserMenu(users, totalUsers);
                break;
            }
            case '3':
            {
                system("cls");
                restoreUserMenu(users, totalUsers);
                break;
            }
            case '4':
            {
                system("cls");
                userMenu(users, *totalUsers);
                break;
            }
            case 27:
            {
                system("cls");
                return option;
            }
        }

    }while (option != '0' && option != 27);

    return option;
}

int registerLoginMenu(stUser *users, int *index)
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
        registerLoginMenu(users, index);
    }


    return id;

}

void deleteUserMenu(stUser *users, int *totalUsers)
{
    int id;

    printf("Seleccione el ID del usuario a eliminar: \n");
    scanf("%d", &id);
    id = matchId(users, id, *totalUsers);
    if(id != -1)
    {
        printf("Desea eliminar al usuario %s? (y/n)\n", users[id].username);

        if (yesNo() == 'y' && !isAdmin(users[id]))
        {
            deleteUser(users, id, totalUsers);
            printf("El usuario fue eliminado.\n");
            system("pause");
        }
        else
        {
            printf("No se elimino al usuario.\n");
            system("pause");
        }
    }
    else
    {
        printf("El usuario no se encuentra.");
        system("pause");
    }
}

void restoreUserMenu(stUser *users, int *totalUsers)
{
    int id;

    stUser deletedUsers[100];
    int totalDeleted = readUserFile(deletedUsers, DELETED_USERS);
    printAllUsers(deletedUsers, totalDeleted);

    printf("\nSeleccione el ID del usuario a restaurar: \n");
    scanf("%d", &id);
    id = matchId(deletedUsers, id, totalDeleted);
    if(id != -1)
    {
        printf("Desea restaurar al usuario %s? (y/n)\n", deletedUsers[id].username);

        if (yesNo() == 'y')
        {
            restoreUser(deletedUsers, id, totalDeleted);
            *totalUsers = readUserFile(users, USERS);
            printf("El usuario fue restaurado.\n");
            system("pause");
        }
        else
        {
            printf("No se restauro al usuario.\n");
            system("pause");
        }
    }
    else
    {
        printf("El usuario no se encuentra.");
        system("pause");
    }
}
