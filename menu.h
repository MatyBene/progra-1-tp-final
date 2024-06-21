#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <conio.h>
#include "Books/book-data.h"
#include "Books/book.h"
#include "Users/user.h"
#include "Users/user-data.h"
#include "validations.h"
#include "Comments/coment-data.h"
#include "Comments/coment.h"

typedef void (*printFunction)(void*, int index);
typedef void (*elementMenu)(void*, int index);

char userMenu(stUser *users, int index, int *totalUsers, stBook *books, int *totalBooks, stComment *comments, int *totalComments);
char adminMenu(stUser *users, int index, int *totalUsers, stBook *books, int *totalBooks, stComment *comments, int *totalComments);
void dashboardMenu(stUser *users, int *totalUsers, stBook *books, int *totalBooks, stComment *comments, int *totalComments);
void userInfoMenu(stUser *users, int index);
int registerLoginMenu(stUser *users, int *index);
void actionUserMenu(stUser *users, int *totalUsers, char *prompt, void (*action)(stUser *, int, int *));
void displayPage(const void elementsArray[], size_t elementSize, int totalElements, int page, int pageSize, printFunction printElement);
int handleUserInput(const void elementsArray[], int totalElements, int currentPage);
void paginated(stBook books[], int totalBooks);

#endif // MENU_H_INCLUDED
