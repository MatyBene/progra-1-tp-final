#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#define F_BOOKS "Files/F_BOOKS.dat"

typedef struct{
    int bookId; /// �nico, autoincremental
    char title[100];
    char publisher[50];
    char author[50];
    char category[50];
    float rating;
    int comments;
    int deleted; /// 0 si est� activo - 1 si est� eliminado
}stBook;

void bookRegister(stBook books[], int *index);

#endif // BOOK_H_INCLUDED
