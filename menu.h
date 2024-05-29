#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "menu.h"
#include "Users/user.h"
#include "Users/user-data.h"
#include "files.h"

int menu(stUser *users, int index);
int registerLogin(stUser *users, int *index);
void userInfo(stUser *users, int index);

#endif // MENU_H_INCLUDED
