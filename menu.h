#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <conio.h>
#include "Files/files.h"
#include "Books/book-data.h"
#include "Books/book.h"
#include "Users/user.h"
#include "Users/user-data.h"
#include "validations.h"
#include "Comments/coment-data.h"
#include "Comments/coment.h"


void run();
void loadDataMenu();
void saveDataMenu();

char userMenu(int index);
char adminMenu(int index);
void userInfoMenu(int index);
int registerLoginMenu();
void actionUserMenu(stUser *users, int *totalUsers, char *prompt, void (*action)(stUser *, int, int *));

#endif // MENU_H_INCLUDED
