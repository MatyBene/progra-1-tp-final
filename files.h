#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Users/user.h"
#include "books/book.h"
#define DELETED_USERS "Files/F_DELETED_USERS.dat"
#define USERS "Files/F_USERS.dat"

int readUserFile (stUser *users, char *fileName);
int readBookFile (stBook *books, char *fileName);
void saveUserFile (stUser *users, char *fileName, int totalUsers);
void appendUserFile (stUser *users, char *fileName, int id);
void deleteUserFile (stUser *users, int totalUsers);
void restoreUserFile (stUser *users, int totalUsers);

#endif // FILES_H_INCLUDED
