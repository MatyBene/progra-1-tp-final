#include "user.h"
#include "user-data.h"
#include "../files.h"

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

int userLogin(stUser *users, int index) // permite al usuario iniciar sesion
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

void printUser(stUser user)
{
    if(user.isAdmin)
    {
        printf("\t\tADMIN\n\n");
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
    users[index].deleted = 1;
    users[index].isAdmin = 0;
    deleteUserFile(users, *totalUsers);
    *totalUsers = readUserFile(users, USERS);
}

void restoreUser(stUser *deletedUsers, int index, int totalDeleted)
{
    deletedUsers[index].deleted = 0;
    restoreUserFile(deletedUsers, totalDeleted);
}

void makeAdmin(stUser *users, int index)
{
    users[index].isAdmin = 1;
}
