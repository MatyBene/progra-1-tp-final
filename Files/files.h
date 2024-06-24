#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "../Users/user.h"
#include "../utilities.h"


int readFile (void *st, size_t stSize, char *fileName);
void saveFile (void *st, size_t stSize, int totalElements, char *fileName, int (*compare)(const void *, const void *));
void deleteFile (void *st, size_t stSize, int index, int totalElements, char *fileName);
void appendFile (void *st, size_t stSize, int index, char *fileName);

#endif // FILES_H_INCLUDED
