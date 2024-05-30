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

    char quit;

    do
    {
        int index = registerLoginMenu(users, &totalUsers);
        if (users[index].isAdmin == 1)
        {
            quit = adminMenu(users, index, &totalUsers);
        }
        else
        {
            quit = userMenu(users, index);
        }
    } while(quit != 27);


    saveUserFile(users, USERS, totalUsers);

    return 0;
}
