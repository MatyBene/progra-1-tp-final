#include "user.h"
#include "user-data.h"
#include "../Files/files.h"

#define USERS "Files/F_USERS.dat"


void userRegister(stUser *users, int *index) // registro de usuarios
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

    appendUserFile(users, USERS, *index);   // guarda el nuevo usuario en el archivo
    (*index)++;
}

int userLogin(stUser *users, int totalUsers) // permite al usuario iniciar sesion
{
    char email[100];
    char password[20];
    int index;

    printf("Iniciar sesion: \n");

    do
    {
        printf("Ingrese su correo electronico: ");
        fflush(stdin);
        gets(email);
        index = existingEmail(email, users, totalUsers);
        if(!index)
        {
            system("cls");
            printf("El mail ingresado no corresponde con un email registrado. \n");
        }
        else if(users[index].deleted)
        {
            system("cls");
            printf("El usuario esta desactivado, solicite la activacion a un admin. \n");
            return -1;
        }
    } while(!index);

    int i = 0;
    do
    {
        printf("Ingrese su contraseña: ");
        getPass(password);
        i++;
        system("cls");

        if (!matchPassword(password, users[index].password))
        {
            if (i == 3)
            {
                printf("Demasiados intentos incorrectos.");
                exit(0);
            }
            printf("Contraseña incorrecta, quedan %d intentos restantes. ", 3-i);
        }

    } while (!matchPassword(password, users[index].password));

    return index;
}

void printUser(stUser user)
{
    if(user.isAdmin)
    {
        printf("\t\tADMIN\n\n");
    }
    else if (user.deleted)
    {
        printf("\t\tDESACTIVADO\n\n");
    }

    printf("ID:....................... %d\n", user.userId);
    printf("User Name:................ %s\n", user.username);
    printf("Email:.................... %s\n", user.email);
    printf("Genero:................... %c\n", user.gender);
    printf("DNI:...................... %s\n", user.dni);
    printf("Direccion:................ %s %s\n", user.address.street, user.address.number);
    printf("Ciudad:................... %s\n", user.address.city);
    printf("Provincia:................ %s\n", user.address.province);
    printf("Pais:..................... %s\n", user.address.country);
    printf("Codigo Postal:............ %s\n", user.address.zipCode);
    printf("Fecha de nacimiento:...... %s\n", user.birthDate);
    printf("\n><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
}

void printAllUsers(stUser *users, int totalUsers)
{
    for (int i = 0; i < totalUsers; i++)
    {
        printUser(users[i]);
    }
}

void deleteUser(stUser *users, int index, int *totalUsers)
{
    deleteUserFile(users, USERS, index, *totalUsers);
    *totalUsers = readUserFile(users, USERS);
}

void disableUser(stUser *users, int index)
{
    users[index].deleted = 1;
    users[index].isAdmin = 0;
}

void activateUser(stUser *users, int index)
{
    users[index].deleted = 0;
}


void makeAdmin(stUser *users, int index)
{
    users[index].isAdmin = 1;
}
