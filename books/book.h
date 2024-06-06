#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#define F_BOOKS "Files/F_BOOKS.dat"

typedef struct{
    int bookId; /// único, autoincremental
    char title[100];
    char publisher[50];
    char author[50];
    char category[50];
    float rating;
    int comments;
    int deleted; /// 0 si está activo - 1 si está eliminado
}stBook;

void bookRegister(stBook books[], int *index);

#endif // BOOK_H_INCLUDED
