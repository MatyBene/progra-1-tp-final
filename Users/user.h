#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USERS "Files/F_USERS.dat"

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
    int numFavorites; /// cantidad de libros favoritos
    char dni[10];
    stAddress address;
    int deleted;  /// 0 si est� activo - 1 si est� eliminado
} stUser;

typedef int (*MatchFunctionUser)(stUser[], int, char[], stUser[], int);

void userRegister(stUser users[], int *index);
int userLogin(stUser users[], int totalUsers);

int enterEmail(stUser users[], int totalUsers);
int enterPassword(stUser users[], int index);

void printUser(const void *elements, int index);
void printUserExtended(const void *elements, int index);

void deleteUser(int idUser, stUser users[], int *totalUsers);

void addFavorite(stUser users[], int userIndex, int bookId);
void removeFavorite(stUser users[], int userIndex, int bookId);

int matchUsername(stUser users[], int totalUsers, char searchUsername[], stUser foundUsers[], int totalFoundUsers);
int matchId(stUser users[], int totalUsers, char searchId[], stUser foundUsers[], int totalFoundUsers);
void searchUsersByUsername(int index, stUser users[], int totalUsers);
void searchUsersById(int index, stUser users[], int totalUsers);

#endif // USER_H_INCLUDED
