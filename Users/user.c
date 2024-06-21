#include "user.h"
#include "user-data.h"
#include "../Files/files.h"

#define USERS "Files/F_USERS.dat"


void userRegister(stUser users[], int *index) // registro de usuarios
{
    users[*index].isAdmin = 0;
    users[*index].deleted = 0;
    users[*index].userId = getFirstFreeId(users, *index);
    newEmail(users, *index);
    newPassword(users, *index);
    newUserName(users, *index);
    newAdress(users, *index);
    newGender(users, *index);
    newBirthDate(users, *index);
    newDni(users, *index);
    printf("El usuario %s fue registrado con exito. Id de usuario: %d.\n", users[*index].username, users[*index].userId);

    appendFile(users, sizeof(stUser), *index, USERS);   // guarda el nuevo usuario en el archivo
    (*index)++;
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

void printUser(void *element)
{
    stUser *user = (stUser*) element;

    if(user->isAdmin)
    {
        printf("\t\tADMIN\n\n");
    }
    else if (user->deleted)
    {
        printf("\t\tDESACTIVADO\n\n");
    }

    printf("ID:....................... %d\n", user->userId);
    printf("User Name:................ %s\n", user->username);
    printf("Email:.................... %s\n", user->email);
    printf("Genero:................... %c\n", user->gender);
    printf("DNI:...................... %s\n", user->dni);
    printf("Direccion:................ %s %s\n", user->address.street, user->address.number);
    printf("Ciudad:................... %s\n", user->address.city);
    printf("Provincia:................ %s\n", user->address.province);
    printf("Pais:..................... %s\n", user->address.country);
    printf("Codigo Postal:............ %s\n", user->address.zipCode);
    printf("Fecha de nacimiento:...... %s\n", user->birthDate);
    printf("\n><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
}

//void printAllUsers(stUser users[], int totalUsers)
//{
//    for (int i = 0; i < totalUsers; i++)
//    {
//        printUser(users, i);
//    }
//}

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
