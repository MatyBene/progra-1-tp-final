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
            printf("Cree una nueva contrase�a: ");
            getPass(pass);
            system("cls");
        } while (!validPassword(pass)); // mientras la contrase�a no sea valida se repite el bucle
        printf("Repita su contrase�a: ");
        getPass(users[index].password);
        system("cls");
    } while (!matchPassword(users[index].password, pass)); // si las contrase�as no coinciden se repite el bucle


}

