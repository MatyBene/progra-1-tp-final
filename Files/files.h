#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "../Users/user.h"
#include "../validations.h"


int readUserFile (stUser *users, char *fileName);
void saveUserFile (stUser *users, char *fileName, int totalUsers);
void appendUserFile (stUser *users, char *fileName, int id);
void deleteUserFile (stUser *users, char *fileName, int index, int totalUsers);

#endif // FILES_H_INCLUDED
