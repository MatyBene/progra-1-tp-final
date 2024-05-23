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


    userRegister(users, 3);
    printf("%s", users[3].email);
}
