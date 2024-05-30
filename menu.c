#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

char userMenu(stUser *users, int index, int *totalUsers)
{

    char option;


    do
    {
        system("cls");
        printf("MENU PRINCIPAL\n\n");
        printf("  0)  Cerrar sesion.\n");
        printf("  1)  Perfil.\n");
        printf("  2)  Editar informacion personal.\n");
        printf("  3)  Eliminar cuenta.\n");
        if (users[index].isAdmin == 1)
        {
            printf("  4)  Menu admin\n");
        }
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
                printUser(users[index]);
                system("pause");
                break;
            }
            case '2':
            {
                userInfoMenu(users, index);
                break;
            }
            case '3':
            {
                printf("Deseas eliminar tu cuenta %s? (y/n)\n", users[index].username);
                if(yesNo())
                {
                    deleteUser(users, index, totalUsers);
                    printf("Se elimino la cuenta.");
                    system("pause");
                }
                else
                {
                    printf("No se elimino la cuenta.");
                    system("pause");
                }
                break;
            }
            case '4':
            {
                system("cls");
                if(!isAdmin(users[index]))
                {
                    option = 1;
                }
                break;
            }
            case 27:
            {
                system("cls");
                break;
            }
        }
    }while (option != '0' && option != 27 && option != '4');

    return option;

}

void userInfoMenu (stUser *users, int index)
{
    char option;

    do
    {
        system("cls");
        printf("INFORMACION PERSONAL\n\n");

        printf("  1)  Editar Email.\n");
        printf("  2)  Editar Contraseña.\n");
        printf("  3)  Editar Nombre de Usuario.\n");
        printf("  4)  Editar Genero (?.\n");
        printf("  5)  Editar Fecha de Nacimiento.\n");
        printf("  6)  Editar Libros Favoritos.\n");
        printf("  7)  Editar DNI.\n");
        printf("  8)  Editar Direccion.\n");
        printf("esc)  Volver.\n");

        fflush(stdin);
        option = getch();

        switch(option)
        {
            case 27:
            {
                system("cls");
                break;
            }
            case '1':
            {
                system("cls");
                newEmail(users, index);
                printf("El mail ha sido actualizado a %s\n", users[index].email);
                system("pause");
                break;
            }
            case '2':
            {
                system("cls");
                newPassword(users, index);
                printf("La contraseña ha sido actualizada\n");
                system("pause");
                break;
            }
            case '3':
            {
                system("cls");
                newUserName(users, index);
                printf("El nombre de usuario ha sido actualizado a %s\n", users[index].username);
                system("pause");
                break;
            }
            case '4':
            {
                system("cls");
                newGender(users, index);
                printf("El genero ha sido actualizado a %c\n", users[index].gender);
                system("pause");
                break;
            }
            case '5':
            {
                system("cls");
                newBirthDate(users, index);
                printf("La fecha de nacimiento ha sido actualizada a %s\n", users[index].birthDate);
                system("pause");
                break;
            }
            case '6':
            {

                break;
            }
            case '7':
            {
                system("cls");
                newDni(users, index);
                printf("El DNI ha sido actualizado a %s\n", users[index].dni);
                system("pause");
                break;
            }
            case '8':
            {
                system("cls");
                newAdress(users, index);
                printf("La direccion ha sido actualizada\n");
                system("pause");
                break;
            }
        }
    }while(option != 27);
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
        printf("  2)  Hacer admin.\n");
        printf("  3)  Eliminar usuario.\n");
        printf("  4)  Restaurar usuario.\n");
        printf("  5)  Ir al menu de usuario.\n");
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
                makeAdminMenu(users, *totalUsers);
                break;
            }
            case '3':
            {
                system("cls");
                deleteUserMenu(users, totalUsers);
                break;
            }
            case '4':
            {
                system("cls");
                restoreUserMenu(users, totalUsers);
                break;
            }
            case '5':
            {
                system("cls");
                option = userMenu(users, index, totalUsers);
                break;
            }
            case 27:
            {
                system("cls");
                break;
            }
        }

    }while (option != '0' && option != 27);

    return option;
}

int registerLoginMenu(stUser *users, int *totalUsers)
{
    char option[9];
    int id = -1;

    printf("Ingrese la accion que desea realizar: (Registrar/Ingresar)\n");
    fflush(stdin);
    gets(option);

    if (strcmpi(option,"registrar") == 0)
    {
        system("cls");
        userRegister(users, totalUsers);
        id = userLogin(users, *totalUsers);
    }
    else if (strcmpi(option,"ingresar") == 0)
    {
        system("cls");
        id = userLogin(users, *totalUsers);
    }
    else
    {
        system("cls");
        printf("La opcion seleccionada no se reconoce.\n");
        registerLoginMenu(users, totalUsers);
    }


    return id;
}

void deleteUserMenu(stUser *users, int *totalUsers)
{
    int id, index;

    printf("Seleccione el ID del usuario a eliminar: \n");
    scanf("%d", &id);
    index = matchId(users, id, *totalUsers);
    if(index != -1)
    {
        printf("Desea eliminar al usuario %s? (y/n)\n", users[index].username);

        if (yesNo() && !isAdmin(users[index]))
        {
            deleteUser(users, index, totalUsers);
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
    int id, index;

    stUser deletedUsers[100];
    int totalDeleted = readUserFile(deletedUsers, DELETED_USERS);
    printAllUsers(deletedUsers, totalDeleted);

    printf("\nSeleccione el ID del usuario a restaurar: \n");
    scanf("%d", &id);
    index = matchId(deletedUsers, id, totalDeleted);
    if(index != -1)
    {
        printf("Desea restaurar al usuario %s? (y/n)\n", deletedUsers[index].username);

        if (yesNo())
        {
            restoreUser(deletedUsers, index, totalDeleted);
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

void makeAdminMenu(stUser *users, int totalUsers)
{
    system("cls");
    int id, index;

    printf("Seleccione el ID del usuario a dar Admin: \n");
    scanf("%d", &id);
    index = matchId(users, id, totalUsers);

    if(index != -1 && !isAdmin(users[index]))
    {
        printf("Desea dar Admin al usuario %s? (y/n)\n", users[index].username);

        if (yesNo())
        {
            makeAdmin(users, index);
        }
    }
    else
    {
        printf("El usuario no es valido.");
    }

    system("pause");
}
