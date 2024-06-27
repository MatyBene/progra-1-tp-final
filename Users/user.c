#include "user.h"
#include "user-data.h"
#include "../Files/files.h"
#include "../menu.h"

#define USERS "Files/F_USERS.dat"


void userRegister(stUser users[], int *totalUsers) /// REGISTRO DE UN NUEVO USUARIO
{
    users[*totalUsers].isAdmin = 0;
    users[*totalUsers].deleted = 0;
    users[*totalUsers].userId = getFirstFreeIdUser(users, *totalUsers);
    newEmail(users, *totalUsers);
    newPassword(users, *totalUsers);
    newUserName(users, *totalUsers);
    newAdress(users, *totalUsers);
    newGender(users, *totalUsers);
    newBirthDate(users, *totalUsers);
    newDni(users, *totalUsers);
    printf("El usuario %s fue registrado con exito. Id de usuario: %d.\n", users[*totalUsers].username, users[*totalUsers].userId);

    appendFile(users, sizeof(stUser), *totalUsers, USERS);   /// GUARDA EL USUARIO EN EL ARCHIVO
    (*totalUsers)++;
}

int userLogin(stUser users[], int totalUsers) /// INICIO DE SESION DE USUARIOS
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

int enterEmail(stUser users[], int totalUsers) /// INGRESO DE EMAIL PARA LOGIN
{
    char email[100];
    int index;

    printf("Ingrese su correo electronico: ");
    fflush(stdin);
    getString(email, 100);
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

int enterPassword(stUser users[], int index) /// INGRESO DE CONTRASEÑA PARA LOGIN
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

void printUser(const void *elements, int index) /// MUESTRA UN USUARIO
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
    printf("Email:.................... %s\n\n", users[index].email);
    printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n");
}

void printUserExtended(const void *elements, int index) /// MUESTRA LOS DETALLES DE UN USUARIO
{
    stUser *users = (stUser*) elements;

    printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n");
    if(users[index].isAdmin)
    {
        printf("\t\tADMIN\n\n");
        printf("ID:....................... %d\n", users[index].userId);
    }
    else if (users[index].deleted)
    {
        printf("\t\tDESACTIVADO\n\n");
    }

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
    printf("\n><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
}

void deleteUser(int idUser, stUser users[], int *totalUsers) /// BORRA PERMANENTEMENTE UN USUARIO
{
    int index = userIndexById(users, idUser, *totalUsers);
    deleteFile(users, sizeof(stUser), index, *totalUsers, USERS);
    *totalUsers = readFile(users, sizeof(stUser), USERS);
}

void addFavorite(stUser users[], int userIndex, int bookId) /// AGREGA UN LIBRO A LOS FAVORITOS DEL USUARIO
{
    users[userIndex].favoriteBooks[users[userIndex].numFavorites] = bookId;

    users[userIndex].numFavorites++;
}

void removeFavorite(stUser users[], int userIndex, int bookId) /// ELIMINA UN LIBRO DE LOS FAVORITOS DEL USUARIO
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

int matchUsername(stUser users[], int totalUsers, char searchUsername[], stUser foundUsers[], int totalFoundUsers) /// CARGA UN ARREGLO CON LAS COINCIDENCIAS DE NOMBRE DE USUARIO Y DEVUELVE LA CANTIDAD DE COINCIDENCIAS
{
    char lowerSearchUsername[100];
    char lowerUsername[100];

    strcpy(lowerSearchUsername, searchUsername);
    toLowerCase(lowerSearchUsername);

    for(int i = 0; i < totalUsers; i++)
    {
        strcpy(lowerUsername, users[i].username);
        toLowerCase(lowerUsername);

        if(strstr(lowerUsername, lowerSearchUsername) != NULL)
        {
            foundUsers[totalFoundUsers] = users[i];
            (totalFoundUsers)++;
        }
    }

    return totalFoundUsers;
}

int matchId(stUser users[], int totalUsers, char searchId[], stUser foundUsers[], int totalFoundUsers) /// CARGA UN ARREGLO CON LAS COINCIDENCIAS DE ID Y DEVUELVE LA CANTIDAD DE COINCIDENCIAS
{
    int searchIndex = userIndexById(users, users[atoi(searchId)].userId, totalUsers);
    if(searchIndex >= 0)
    {
        foundUsers[0] = users[searchIndex];
        totalFoundUsers = 1;
    }

    return totalFoundUsers;
}

void searchUsersBy(int index, stUser users[], int totalUsers, const char *prompt, MatchFunctionUser matchFunc){ /// FUNCION GENERICA PARA BUSCAR USUARIOS POR PARAMETRO
    char searchTerm[100];
    stUser foundUsers[20];
    int totalFoundUsers = 0;

    system("cls");
    printf("%s\n", prompt);
    getString(searchTerm, 100);

    totalFoundUsers = matchFunc(users, totalUsers, searchTerm, foundUsers, totalFoundUsers);

    if (totalFoundUsers == 0)
    {
        printf("No se encontro ningun usuario con ese criterio.");
        sleep(1);
    }
    else
    {
        paginated(index, foundUsers, &totalFoundUsers, 5, printUserExtended, userHandleMenu);
    }
}

void searchUsersByUsername(int index, stUser users[], int totalUsers) /// BUSCA USUARIOS POR NOMBRE DE USUARIO
{
    searchUsersBy(index, users, totalUsers, "Ingrese el nombre de usuario:", matchUsername);
}

void searchUsersById(int index, stUser users[], int totalUsers) /// BUSCA USUARIOS POR ID
{
    searchUsersBy(index, users, totalUsers, "Ingrese el numero de ID:", matchId);
}

