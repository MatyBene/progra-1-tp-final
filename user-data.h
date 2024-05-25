#include "user.h"

void newEmail (stUser *users, int index);
int validEmail(char *email);
int existingEmail(char *email, stUser *users, int index);
void getPass(char *pass);
void newPassword(stUser *users, int index);
int validPassword(char *pass);
int matchPassword(char *pass1, char *pass2);
void newUserName (stUser *users, int index);
int validUserName(char *uName, stUser *users, int index);
void newAdress (stUser *users, int index);
void newGender(stUser *users, int index);
void newBirthDate(stUser *users, int index);
int validDate(int year, int month, int day);
void newDni(stUser *users, int index);
int validDni(char *dni);
//void newFavoriteBook(stUser users, int index);
