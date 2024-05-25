#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "user.h"
#include "files.h"

void menu()
{
    stUser users[1000];
    int totalUsers = readUserFile(users, "Files/F_USERS.txt", sizeof(stUser));



//    userRegister(users, totalUsers);




}
