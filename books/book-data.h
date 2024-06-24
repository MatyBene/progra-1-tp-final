#ifndef BOOK_DATA_H_INCLUDED
#define BOOK_DATA_H_INCLUDED

#include "book.h"
#include "../utilities.h"
#include "../Users/user.h"

void newTitle(stBook books[], int index);
void newPublisher(stBook books[], int index);
void newAuthor(stBook books[], int index);
void newCategory(stBook books[], int index);
int fisrtFreeIdBook(stBook books[], int totalBooks);

#endif // BOOK_DATA_H_INCLUDED
