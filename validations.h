#ifndef VALIDATIONS_H_INCLUDED
#define VALIDATIONS_H_INCLUDED

#include "Users/user.h"
#include "books/book.h"

/* >>>>>>>>>>>>>>>>>>>BOOKS<<<<<<<<<<<<<<<<<<<<< */


int isNotEmpty(char field[]);
char yesNo ();


/* >>>>>>>>>>>>>>>>>>>BOOKS<<<<<<<<<<<<<<<<<<<<< */


int existingBook(char title[], stBook books[], int index);


/* >>>>>>>>>>>>>>>>>>>USERS<<<<<<<<<<<<<<<<<<<<< */


int validEmail(char *email);
int existingEmail(char *email, stUser *users, int index);
int validPassword(char *pass);
int matchPassword(char *pass1, char *pass2);
int validUserName(char *uName, stUser *users, int index);
int validGender(char gender);
int validDate(int year, int month, int day);
int validDni(char *dni);
int isUserDeleted(stUser user);
int isAdmin(stUser user);
int matchId (stUser *users, int id, int totalUsers);
int compareUserId(const void *a, const void *b);


/* >>>>>>>>>>>>>>>>>>>USERS<<<<<<<<<<<<<<<<<<<<< */


#endif // VALIDATIONS_H_INCLUDED