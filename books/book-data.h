#ifndef BOOK-DATA_H_INCLUDED
#define BOOK-DATA_H_INCLUDED

#include "book.h"

/* --VALIDACIONES-- */
int isNotEmpty(char field[]);
int existingBook(char title[], stBook books[], int index);
/* --VALIDACIONES-- */

void newTitle(stBook books[], int index);
void newField(char field[], char prompt[]);
void newPublisher(stBook books[], int index);
void newAuthor(stBook books[], int index);
void newCategory(stBook books[], int index);

#endif // BOOK-DATA_H_INCLUDED
