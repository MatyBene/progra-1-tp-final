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

//    for(int i = 0; i < totalUsers; i ++)
//    {
//        users[i].userId--;
//    }
//    users[100].isAdmin = 1;

    int quit = 0;

    do
    {
        int id = registerLogin(users, &totalUsers);
        if (users[id].isAdmin == 1)
        {
            adminMenu(users, id, &totalUsers);
        }
        else
        {
            quit = menu(users, id);
        }
    } while(quit != 3);


    saveUserFile(users, USERS, totalUsers);

    return 0;
}
