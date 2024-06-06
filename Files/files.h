#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "../Users/user.h"
#include "../validations.h"


int readFile (void *st, size_t stSize, char *fileName);
void saveFile (void *st, size_t stSize, int totalElements, char *fileName);
void appendUserFile (stUser *users, char *fileName, int id);
void deleteUserFile (stUser *users, char *fileName, int index, int totalUsers);

#endif // FILES_H_INCLUDED
