#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

typedef struct{
    int bookId; /// �nico, autoincremental
    char title[100];
    char publisher[50];
    char author[50];
    char category[50];
    float rating;
    int deleted; /// 0 si est� activo - 1 si est� eliminado
}stBook;

#endif // BOOK_H_INCLUDED
