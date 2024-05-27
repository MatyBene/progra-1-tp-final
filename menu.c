#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "Users/user.h"
#include "files.h"

void menu()
{
    stUser users[1000];
    int totalUsers = readUserFile(users, "Users/F_USERS.dat");

//    userRegister(users, &totalUsers);

    for(int i = 0; i < totalUsers; i++)
    {
        printUser(users, i);
    }

    userLogin(users, totalUsers);

    saveUserFile(users, "Users/F_USERS.dat", totalUsers);


//    userRegister(users, totalUsers);




}
