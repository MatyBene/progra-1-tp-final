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

char userMenu(int index);
char adminMenu(int index);
void userInfoMenu(int index);
int registerLoginMenu();
void actionUserMenu(stUser *users, int *totalUsers, char *prompt, void (*action)(stUser *, int, int *));
void paginated(void elements[], int *totalElements, printFunction printElement, elementMenu handleMenu, char elementName[]);
void displayPage(const void elements[], int totalElements, int page, int pageSize, printFunction printElement);
int handleUserInput(const void elements[], int *totalElements, int currentPage);

#endif // MENU_H_INCLUDED
