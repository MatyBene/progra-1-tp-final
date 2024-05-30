#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "menu.h"
#include "Users/user.h"
#include "Users/user-data.h"
#include "files.h"

char userMenu(stUser *users, int index, int *totalUsers);
char adminMenu(stUser *users, int index, int *totalUsers);
void userInfoMenu(stUser *users, int index);
int registerLoginMenu(stUser *users, int *index);
void deleteUserMenu(stUser *users, int *totalUsers);
void restoreUserMenu(stUser *users, int *totalUsers);
void makeAdminMenu(stUser *users, int totalUsers);

#endif // MENU_H_INCLUDED
