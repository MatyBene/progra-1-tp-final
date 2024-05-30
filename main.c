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
        int id = registerLoginMenu(users, &totalUsers);
        if (users[id].isAdmin == 1)
        {
            quit = adminMenu(users, id, &totalUsers);
        }
        else
        {
            quit = userMenu(users, id);
        }
    } while(quit != '0' && quit != 27);


    saveUserFile(users, USERS, totalUsers);

    return 0;
}
