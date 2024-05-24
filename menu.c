#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "user.h"

void menu()
{
    stUser users[1000];

    strcpy(users[0].email, "pepito@hotmail.com");
    strcpy(users[1].email, "ramirito@gmail.com");
    strcpy(users[2].email, "covid@yahoo.com");
    strcpy(users[0].username, "pepito");
    strcpy(users[1].username, "ramirito");
    strcpy(users[2].username, "covid");

    int totalUsers = 3;
    userRegister(users, &totalUsers);

    printf("%s\n", users[3].email);
    printf("%s\n", users[3].username);

}
