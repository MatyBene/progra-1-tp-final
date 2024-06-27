#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include <ctype.h>
#include <conio.h>
#include "Books/book.h"
#include "Users/user.h"
#include "Comments/coment.h"
#include <unistd.h>

int isNotEmpty(char field[]);
int yesNo ();
void printWithLineBreaks(char *str, int charsBeforLinebreak);
void newField(char field[], char prompt[], int maxBufferSize);
int getNumber(); // permite escribir unicamente numeros
void getString(char* str, int maxBufferSize);


/* >>>>>>>>>>>>>>>>>>>VALIDATIONS<<<<<<<<<<<<<<<<<<<<< */

int existingBook(char title[], stBook books[], int index);
int isFavorite(stUser user, int bookId);
int validEmail(char *email);
int existingEmail(char *email, stUser *users, int index);
int validPassword(char *pass);
int matchPassword(char *pass1, char *pass2);
int validUserName(char *uName, stUser *users, int index);
int validGender(char gender);
int validDate(int year, int month, int day);
int validDni(char *dni);


/* >>>>>>>>>>>>>>>>>>>VALIDATIONS<<<<<<<<<<<<<<<<<<<<< */


#endif // UTILITIES_H_INCLUDED
