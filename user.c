#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

void userRegister(stUser *users)
{
    stUser newUser;

    printf("Ingrese un mail valido: ");
    fflush(stdin);
    gets(newUser.email);

    while (!validEmail(newUser.email))
    {
        printf("El mail ingresado ya existe o no es valido, por favor intente nuevamente: ");
        gets(newUser.email);
    }

}

int existingEmail(char *mail, stUser *users)
{
    ///totalUsers = countUsers(users);
    int i = 0, flag = 0;

    while (i < totalUsers && flag == 0)
    {
        if (strcmpi(users[i].email, mail))
        {
            flag = 1;
        }
        i++;
    }

    return flag;
}

int validEmail(char *email)
{
    int i = 0, a = 0, com = 0;

    while(email[i] != 0)
    {
        if (email[i] == '@')
        {
            a = 1;
        }
        if (email[i] == '.' && a == 1)
        {
            if (email[i + 1] == 'c' && email[i + 2] == 'o' && email[i + 3] == 'm')
            {
                com = 1;
            }
        }

        i++;
    }

    return com;
}
