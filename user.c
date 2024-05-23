#include "user-data.h"
#include "user.h"

void userRegister(stUser *users, int index) // registro de usuarios
{
    newEmail(users, 3);

    char pass[21];

    do
    {
        do
        {
            printf("Cree una nueva contraseņa: ");
            getPass(pass);
            system("cls");
        } while (!validPassword(pass)); // mientras la contraseņa no sea valida se repite el bucle
        printf("Repita su contraseņa: ");
        getPass(users[index].password);
        system("cls");
    } while (!matchPassword(users[index].password, pass)); // si las contraseņas no coinciden se repite el bucle


}

