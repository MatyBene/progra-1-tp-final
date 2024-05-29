#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "menu.h"
#define USERS "Files/F_USERS.dat"


int main()
{
    setlocale(LC_ALL, "spanish");

    stUser users[1000];
    int totalUsers = readUserFile(users, USERS);

    int quit = 0;

    do
    {
        registerLogin(users, &totalUsers);
        quit = menu(users, &totalUsers);
    } while(quit != 27);


    saveUserFile(users, USERS, totalUsers);

    return 0;
}
