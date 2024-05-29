#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Users/user.h"
#define DELETED_USERS "Files/F_DELETED_USERS.dat"

int readUserFile (stUser *users, char *fileName);
void saveUserFile (stUser *users, char *fileName, int totalUsers);
void appendUserFile (stUser *users, int id, char *fileName);
int restoreUserFile (stUser *users, char *fileName);

#endif // FILES_H_INCLUDED
