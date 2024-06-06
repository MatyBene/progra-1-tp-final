#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <conio.h>
#include "Users/user.h"
#include "Users/user-data.h"
#include "validations.h"

char userMenu(stUser *users, int index, int *totalUsers);
char adminMenu(stUser *users, int index, int *totalUsers);
void userInfoMenu(stUser *users, int index);
int registerLoginMenu(stUser *users, int *index);
void actionUserMenu(stUser *users, int *totalUsers, char *prompt, void (*action)(stUser *, int, int *));

#endif // MENU_H_INCLUDED
