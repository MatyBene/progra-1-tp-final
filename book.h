#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

typedef struct{
    int bookId; /// único, autoincremental
    char title[100];
    char publisher[50];
    char author[50];
    char category[50];
    float rating;
    int deleted; /// 0 si está activo - 1 si está eliminado
}stBook;

#endif // BOOK_H_INCLUDED
