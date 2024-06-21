#ifndef COMENT_H_INCLUDED
#define COMENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define COMMENTS "Files/F_COMMENTS.dat"

typedef struct
{
    int commentId; /// único, autoincremental
    int bookId;
    int userId;
    char commentTitle[100];
    char description[500];
    int rating; /// de 0 a 5 "estrellas"
    char commentDate[20]; /// o se puede hacer con dia, mes, anio.
    int deleted; /// 0 si está activo - 1 si está eliminado
} stComment;

void commentRegister(stComment comments[], int *index);
void printComment(const void *elements, int index);
void printCommentAdmin(const void *elements, int index);


#endif // COMENT_H_INCLUDED
