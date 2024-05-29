#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

int menu(stUser *users, int *index)
{
//    if (users[index].isAdmin == 1)
//    {
//        menuAdmin();
//    }
    int option;

    do
    {
        system("cls");
        printf("MENU PRINCIPAL\n\n");
        printf(" 0)  Cerrar sesion.\n");
        printf(" 1)  Perfil.\n");
        printf(" 2)  Editar informacion personal.\n");
        if (users[*index].isAdmin == 1)
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
    }while (option != 0);

    return option;

}

void userInfo (stUser *users, int index)
{
    int option;

    do
    {
        system("cls");
        printf("INFORMACION PERSONAL\n\n");

        printf(" 0)  Volver.\n");
        printf(" 1)  Editar Email.\n");
        printf(" 2)  Editar Contraseña.\n");
        printf(" 3)  Editar Nombre de Usuario.\n");
        printf(" 4)  Editar Genero (?.\n");
        printf(" 5)  Editar Fecha de Nacimiento.\n");
        printf(" 6)  Editar Libros Favoritos.\n");
        printf(" 7)  Editar DNI.\n");
        printf(" 8)  Editar Direccion.\n");

        scanf("%d", &option);

        switch(option)
        {
            case 0:
            {
                break;
            }
            case 1:
            {
                system("cls");
                newEmail(users, index);
                printf("El mail ha sido actualizado a %s\n", users[index].email);
                system("pause");
                break;
            }
            case 2:
            {
                system("cls");
                newPassword(users, index);
                printf("La contraseña ha sido actualizada\n");
                system("pause");
                break;
            }
            case 3:
            {
                system("cls");
                newUserName(users, index);
                printf("El nombre de usuario ha sido actualizado a %s\n", users[index].username);
                system("pause");
                break;
            }
            case 4:
            {
                system("cls");
                newGender(users, index);
                printf("El genero ha sido actualizado a %c\n", users[index].gender);
                system("pause");
                break;
            }
            case 5:
            {
                system("cls");
                newBirthDate(users, index);
                printf("La fecha de nacimiento ha sido actualizada a %s\n", users[index].birthDate);
                system("pause");
                break;
            }
            case 6:
            {

                break;
            }
            case 7:
            {
                system("cls");
                newDni(users, index);
                printf("El DNI ha sido actualizado a %s\n", users[index].dni);
                system("pause");
                break;
            }
            case 8:
            {
                system("cls");
                newAdress(users, index);
                printf("La direccion ha sido actualizada\n");
                system("pause");
                break;
            }

        }
    }while(option != 0);
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

void adminMenu()
{

}
