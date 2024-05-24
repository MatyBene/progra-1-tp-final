#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

typedef struct{
    char street[50];
    char number[10];
    char zipCode[10];
    char city[50];
    char province[50];
    char country[50];
} stAddress;

typedef struct{
    int userId;
    char email[100];
    char password[20];
    char username[20];
    int isAdmin;  /// 1 = si  0 = no
    char gender;
    char birthDate[20];   /// o se puede hacer con dia, mes, a�o.
    int favoriteBooks[50];  /// se van a guardar los id de los libros favs.
    char ssn[10];
    stAddress address;
    int deleted;  /// 0 si est� activo - 1 si est� eliminado
} stUser;

void userRegister(stUser *users, int *index);


#endif // USER_H_INCLUDED
