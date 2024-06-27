#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <conio.h>
#include "Files/files.h"
#include "Books/book-data.h"
#include "Books/book.h"
#include "Users/user.h"
#include "Users/user-data.h"
#include "utilities.h"
#include "Comments/coment-data.h"
#include "Comments/coment.h"



typedef void (*printFunction)(const void*, int index);
typedef void (*elementMenu)(int userIndex, void *elements, int *totalElements, int elementIndex);
typedef void (*actionFunction)(stUser users[], int index, int *totalUsers);

void run();
void readDataMenu();
void saveDataMenu();
int registerLoginMenu();

char userMenu(int index);
char adminMenu(int index);

void dashboardMenu(int index);
void userInfoMenu(int index);

void paginated(int index, void *elements, int *totalElements, int pageSize, printFunction printElement, elementMenu handleMenu);
void displayPage(const void *elements, int totalElements, int page, int pageSize, printFunction printElement);
int handleInput(int index, void *elements, int *totalElements, int currentPage, elementMenu handleMenu);

void sortBooksMenu(int index, void *elements, int *totalElements);
void bookHandleMenu(int index, void *elements, int *totalElements, int bookIndex);
void userHandleMenu(int index, void *elements, int *totalElements, int userIndex);
void commentHandleMenu(int index, void *elements, int *totalElements, int commentIndex);
void searchBooksMenu(int index);
void searchUsersMenu(int index);
void editBookMenu(int idBook);
void editCommentMenu(int idComment);

#endif // MENU_H_INCLUDED
