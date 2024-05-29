#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Users/user.h"

int readUserFile (stUser *users, char *fileName);
void saveUserFile (stUser *users, char *fileName, int totalUsers);
void appendUserFile (stUser *users, char *fileName, int id);

#endif // FILES_H_INCLUDED
