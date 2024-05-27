#include "user-data.h"
#include "user.h"

void userRegister(stUser *users, int *index) // registro de usuarios
{
    users[*index].isAdmin = 0;
    users[*index].deleted = 0;
    users[*index].userId = (*index) + 1;
    newEmail(users, *index);
    newPassword(users, *index);
    newUserName(users, *index);
    newAdress(users, *index);
    newGender(users, *index);
    newBirthDate(users, *index);
    newDni(users, *index);
    printf("El usuario %s fue registrado con exito. Id de usuario: %d.", users[*index].username, users[*index].userId);
    (*index)++;

}

void userLogin(stUser *users, int index)
{
    char email[100];
    char password[20];


    do
    {
        printf("Ingrese su correo electronico: ");
        fflush(stdin);
        gets(email);
        if(!matchEmail(email, users, index))
        {
            system("cls");
            printf("El mail ingresado no corresponde con un email registrado. ");
        }
    } while(!matchEmail(email, users, index));

    int i = 0;
    do
    {
        printf("Ingrese su contraseņa: ");
        getPass(password);
        i++;
        system("cls");

        if (!matchPassword(password, users[matchEmail(email, users, index)].password))
        {
            if (i == 3)
            {
                printf("Demasiados intentos incorrectos.");
                exit(0);
            }
            printf("Contraseņa incorrecta, quedan %d intentos restantes. ", 3-i);
        }

    } while (!matchPassword(password, users[matchEmail(email, users, index)].password));

}

void printUser(stUser *users, int index)
{
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

