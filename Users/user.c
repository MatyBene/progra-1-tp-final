#include "user.h"
#include "user-data.h"
#include "../files.h"

#define USERS "Files/F_USERS.dat"

int userRegister(stUser *users, int *index) // registro de usuarios
{
    users[*index].isAdmin = 0;
    users[*index].deleted = 0;
    users[*index].userId = (*index);
    newEmail(users, *index);
    newPassword(users, *index);
    newUserName(users, *index);
    newAdress(users, *index);
    newGender(users, *index);
    newBirthDate(users, *index);
    newDni(users, *index);
    printf("El usuario %s fue registrado con exito. Id de usuario: %d.\n", users[*index].username, users[*index].userId);
    (*index)++;

    saveUserFile(users, USERS, *index);

    return userLogin(users, *index);

}

int userLogin(stUser *users, int index)
{
    char email[100];
    char password[20];

    printf("Iniciar sesion: \n");

    do
    {
        printf("Ingrese su correo electronico: ");
        fflush(stdin);
        gets(email);
        if(!existingEmail(email, users, index))
        {
            system("cls");
            printf("El mail ingresado no corresponde con un email registrado. \n");
        }
    } while(!existingEmail(email, users, index));

    int i = 0;
    do
    {
        printf("Ingrese su contraseña: ");
        getPass(password);
        i++;
        system("cls");

        if (!matchPassword(password, users[existingEmail(email, users, index)].password))
        {
            if (i == 3)
            {
                printf("Demasiados intentos incorrectos.");
                exit(0);
            }
            printf("Contraseña incorrecta, quedan %d intentos restantes. ", 3-i);
        }

    } while (!matchPassword(password, users[existingEmail(email, users, index)].password));

    return existingEmail(email, users, index);

}

void printUser(stUser *users, int index)
{
    printf("\t\tADMIN\n\n");
    printf("ID:....................... %d\n", users[index].userId);
    printf("User Name:................ %s\n", users[index].username);
    printf("Email:.................... %s\n", users[index].email);
    printf("Genero:................... %c\n", users[index].gender);
    printf("DNI:...................... %s\n", users[index].dni);
    printf("Direccion:................ %s %s\n", users[index].address.street, users[index].address.number);
    printf("Ciudad:................... %s\n", users[index].address.city);
    printf("Provincia:................ %s\n", users[index].address.province);
    printf("Pais:..................... %s\n", users[index].address.country);
    printf("Codigo Postal:............ %s\n", users[index].address.zipCode);
    printf("Fecha de nacimiento:...... %s\n", users[index].birthDate);
    printf("\n><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
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

void printAllUsers(stUser *users, int totalUsers)
{
    for (int i = 0; i < totalUsers; i++)
    {
        printUser(users, i);
    }
}

void deleteUser(stUser *users, int id, int *totalUsers)
{
    users[id].deleted = 1;
    saveUserFile(users, USERS, *totalUsers);
    *totalUsers = readUserFile(users, USERS);
}
