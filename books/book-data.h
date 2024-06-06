#ifndef BOOK_DATA_H_INCLUDED
#define BOOK_DATA_H_INCLUDED

#include "book.h"
#include "../validations.h"
#include "../Users/user.h"

void newTitle(stBook books[], int index);
void newField(char field[], char prompt[]);
void newPublisher(stBook books[], int index);
void newAuthor(stBook books[], int index);
void newCategory(stBook books[], int index);

#endif // BOOK_DATA_H_INCLUDED
