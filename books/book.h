#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <ctype.h>

#define BOOKS "Files/F_BOOKS.dat"

typedef struct{
    int bookId; /// �nico, autoincremental
    char title[100];
    char publisher[50];
    char author[50];
    char category[50];
    float rating;
    int deleted; /// 0 si est� activo - 1 si est� eliminado
}stBook;

void bookRegister(stBook books[], int *index);
void printBookAdmin(const void *elements, int index);
void printBook(const void *elements, int index);
void printBookExtended(const void *elements, int index);

int compareBookId(const void *a, const void *b);
int compareRating(const void *a, const void *b);
int compareTitle(const void *a, const void *b);
int compareCategory(const void *a, const void *b);
void toLowerCase(char *str);

void searchBooks(int index, stBook books[], int totalBooks);
void searchBooksByTitle(int index, stBook books[], int totalBooks);
int matchTitleBook(stBook books[], int totalBooks, char searchTitle[], stBook foundBooks[], int totalFoundBooks);
void searchBooksByAuthor(int index, stBook books[], int totalBooks);
int matchAuthorBook(stBook books[], int totalBooks, char searchAuthor[], stBook foundBooks[], int totalFoundBooks);
void searchBooksByCategory(int index, stBook books[], int totalBooks);
int matchCategoryBook(stBook books[], int totalBooks, char searchCategory[], stBook foundBooks[], int totalFoundBooks);

#endif // BOOK_H_INCLUDED
