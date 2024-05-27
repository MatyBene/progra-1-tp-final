#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "menu.h"
#define USERS "Users/F_USERS.dat"


int main()
{
    setlocale(LC_ALL, "spanish");

    stUser users[1000];
    int totalUsers = readUserFile(users, USERS);

    registerLogin(users, &totalUsers);
    menu();

    saveUserFile(users, USERS, totalUsers);

    return 0;
}
