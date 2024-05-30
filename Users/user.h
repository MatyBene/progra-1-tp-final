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
    char birthDate[20];   /// yyy/mm/dd
    int favoriteBooks[50];  /// se van a guardar los id de los libros favs.
    char dni[10];
    stAddress address;
    int deleted;  /// 0 si está activo - 1 si está eliminado
} stUser;

int userRegister(stUser *users, int *index);
int userLogin(stUser *users, int index);
void printUser(stUser user);
void userInfo(stUser *users, int index);
void printAllUsers(stUser *users, int index);
void deleteUser(stUser *users, int id, int *totalUsers);
void restoreUser(stUser *deletedUsers, int id, int totalDeleted);

#endif // USER_H_INCLUDED
