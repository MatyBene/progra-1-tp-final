#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "user.h"

int countFile(char *fileName);
int readFile (stUser *users, char *fileName, size_t st);

#endif // FILES_H_INCLUDED
