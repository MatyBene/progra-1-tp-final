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
            printf("Cree una nueva contraseña: ");
            getPass(pass);
            system("cls");
        } while (!validPassword(pass)); // mientras la contraseña no sea valida se repite el bucle
        printf("Repita su contraseña: ");
        getPass(users[index].password);
        system("cls");
    } while (!matchPassword(users[index].password, pass)); // si las contraseñas no coinciden se repite el bucle


}

