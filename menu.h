#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "menu.h"
#include "Users/user.h"
#include "Users/user-data.h"
#include "files.h"

char menu(stUser *users, int index);
int registerLogin(stUser *users, int *index);
char adminMenu(stUser *users, int index, int *totalUsers);

#endif // MENU_H_INCLUDED
