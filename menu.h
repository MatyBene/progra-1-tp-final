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
void readDataMenu();
void saveDataMenu();

typedef void (*printFunction)(const void*, int index);
typedef void (*elementMenu)(int userIndex, int elementIndex);
typedef void (*actionFunction)(stUser users[], int index, int *totalUsers);

int registerLoginMenu();

char userMenu(int index);
char adminMenu(int index);

void dashboardMenu();
void userInfoMenu(int index);
void actionUserMenu(char *prompt, void (*action)(stUser *, int, int *));

void paginated(int index, void *elements, int *totalElements, int pageSize, printFunction printElement, elementMenu handleMenu);
void displayPage(const void *elements, int totalElements, int page, int pageSize, printFunction printElement);
int handleUserInput(int index, void *elements, int *totalElements, int currentPage, elementMenu handleMenu);

void sortBooksMenu();
void booksOptionMenu(int userIndex, int bookIndex);

#endif // MENU_H_INCLUDED
