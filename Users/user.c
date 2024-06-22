#include "user.h"
#include "user-data.h"
#include "../Files/files.h"

#define USERS "Files/F_USERS.dat"


void userRegister(stUser users[], int *totalUsers) // registro de usuarios
{
    users[*totalUsers].isAdmin = 0;
    users[*totalUsers].deleted = 0;
    users[*totalUsers].userId = getFirstFreeId(users, *totalUsers);
    newEmail(users, *totalUsers);
    newPassword(users, *totalUsers);
    newUserName(users, *totalUsers);
    newAdress(users, *totalUsers);
    newGender(users, *totalUsers);
    newBirthDate(users, *totalUsers);
    newDni(users, *totalUsers);
    printf("El usuario %s fue registrado con exito. Id de usuario: %d.\n", users[*totalUsers].username, users[*totalUsers].userId);

    appendFile(users, sizeof(stUser), *totalUsers, USERS);   // guarda el nuevo usuario en el archivo
    (*totalUsers)++;
}

int userLogin(stUser users[], int totalUsers) // permite al usuario iniciar sesion
{
    int index;

    printf("Iniciar sesion: \n");

    do
    {
        index = enterEmail(users, totalUsers);
    } while(!index);

    index = enterPassword(users, index);

    return index;
}

int enterEmail(stUser users[], int totalUsers)
{
    char email[100];
    int index;

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
        index = -1;
    }
    return index;
}

int enterPassword(stUser users[], int index)
{
    char password[20];
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
                printf("Demasiados intentos incorrectos.\n");
                return -1;
            }
            printf("Contraseña incorrecta, quedan %d intentos restantes. ", 3-i);
        }
    } while (!matchPassword(password, users[index].password));

    return index;
}

void printUser(const void *elements, int index)
{
    stUser *users = (stUser*) elements;

    if(users[index].isAdmin)
    {
        printf("\t\tADMIN\n\n");
    }
    else if (users[index].deleted)
    {
        printf("\t\tDESACTIVADO\n\n");
    }

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

void deleteUser(stUser users[], int index, int *totalUsers)
{
    deleteFile(users, sizeof(stUser), index, *totalUsers, USERS);
    *totalUsers = readFile(users, sizeof(stUser), USERS);
    printf("Se elimino al usuario.\n");
}

void disableUser(stUser users[], int index, int *totalUsers)
{
    if(!users[index].deleted)
    {
        users[index].deleted = 1;
        users[index].isAdmin = 0;
        printf("Se desactivo al usuario.\n");
    }
    else
    {
        printf("El usuario ya esta desactivado.\n");
    }
}

void activateUser(stUser users[], int index, int *totalUsers)
{
    if(users[index].deleted)
    {
        users[index].deleted = 0;
        printf("Se activo al usuario.\n");
    }
    else
    {
        printf("El usuario no esta desactivado.\n");
    }
}


void makeAdmin(stUser users[], int index, int *totalUsers)
{
    if(!users[index].isAdmin)
    {
        users[index].isAdmin = 1;
        printf("Se dio admin al usuario.\n");
    }
    else
    {
        printf("El usuario no es valido.\n");
    }
}

void addFavorite(stUser users[], int userIndex, int bookId)
{
    users[userIndex].favoriteBooks[users[userIndex].numFavorites] = bookId;

    users[userIndex].numFavorites++;
}

void removeFavorite(stUser users[], int userIndex, int bookId)
{
    users[userIndex].numFavorites--;

    int j = 0, i = 0;

    while (i < users[userIndex].numFavorites)
    {
        if(users[userIndex].favoriteBooks[j] != bookId)
        {
           users[userIndex].favoriteBooks[i] = users[userIndex].favoriteBooks[j];
           i++;
        }

        j++;
    }
}
