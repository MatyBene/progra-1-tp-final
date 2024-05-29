#ifndef VALIDATIONS_H_INCLUDED
#define VALIDATIONS_H_INCLUDED

#include "Users/user.h"
#include "books/book.h"

/* >>>>>>>>>>>>>>>>>>>BOOKS<<<<<<<<<<<<<<<<<<<<< */


int isNotEmpty(char field[]);
int existingBook(char title[], stBook books[], int index);


/* >>>>>>>>>>>>>>>>>>>BOOKS<<<<<<<<<<<<<<<<<<<<< */




/* >>>>>>>>>>>>>>>>>>>USERS<<<<<<<<<<<<<<<<<<<<< */


int validEmail(char *email);
int existingEmail(char *email, stUser *users, int index);
int validPassword(char *pass);
int matchPassword(char *pass1, char *pass2);
int validUserName(char *uName, stUser *users, int index);
int validGender(char gender);
int validDate(int year, int month, int day);
int validDni(char *dni);


/* >>>>>>>>>>>>>>>>>>>USERS<<<<<<<<<<<<<<<<<<<<< */


#endif // VALIDATIONS_H_INCLUDED
