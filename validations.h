#ifndef VALIDATIONS_H_INCLUDED
#define VALIDATIONS_H_INCLUDED

#include <ctype.h>
#include <conio.h>
#include "Books/book.h"
#include "Users/user.h"
#include "Comments/coment.h"

int isNotEmpty(char field[]);
int yesNo ();
void newField(char field[], char prompt[]);
int getNumber(); // permite escribir unicamente numeros

/* >>>>>>>>>>>>>>>>>>>BOOKS<<<<<<<<<<<<<<<<<<<<< */


int existingBook(char title[], stBook books[], int index);
int isFavorite(stUser user, int bookId);

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
int matchId (stUser *users, int id, int totalUsers);
int compareUserId(const void *a, const void *b);


/* >>>>>>>>>>>>>>>>>>>USERS<<<<<<<<<<<<<<<<<<<<< */


/* >>>>>>>>>>>>>>>>>>>COMMENTS<<<<<<<<<<<<<<<<<<<<< */

int compareCommentId(const void *a, const void *b);

/* >>>>>>>>>>>>>>>>>>>COMMENTS<<<<<<<<<<<<<<<<<<<<< */


#endif // VALIDATIONS_H_INCLUDED
