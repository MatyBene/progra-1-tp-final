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

typedef void (*printFunction)(void*, int index);
typedef void (*elementMenu)(stUser *user, int userIndex, void elements[], int index, int *totalElements);
typedef void (*actionFunction)(stUser users[], int index, int *totalUsers);

int registerLoginMenu();

char userMenu(int index);
char adminMenu(int index);

void dashboardMenu();
void userInfoMenu(int index);
void actionUserMenu(char *prompt, void (*action)(stUser *, int, int *));

void paginated(int userIndex, int pageSize, printFunction printElement, elementMenu handleMenu);
void displayPage(int page, int pageSize, printFunction printElement);
int handleUserInput(int userIndex, int currentPage, elementMenu handleMenu);

#endif // MENU_H_INCLUDED
