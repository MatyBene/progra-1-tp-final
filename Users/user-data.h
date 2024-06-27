#ifndef USER_DATA_H_INCLUDED
#define USER_DATA_H_INCLUDED

#include <conio.h>
#include <ctype.h>
#include "user.h"
#include "../utilities.h"

void newEmail (stUser *users, int index);
void getPass(char *pass);
int getFirstFreeIdUser (stUser *users, int totalUsers);
void newPassword(stUser *users, int index);
void newUserName (stUser *users, int index);
void newAdress (stUser *users, int index);
void newGender(stUser *users, int index);
void newBirthDate(stUser *users, int index);
void newDni(stUser *users, int index);
void newStreet(stUser *users, int index);
void newZipCode(stUser *users, int index);
void newCity(stUser *users, int index);
void newProvince(stUser *users, int index);
void newCountry(stUser *users, int index);
int compareUserId(const void *a, const void *b);
int userIndexById (stUser *users, int id, int totalUsers);


#endif // USER_DATA_H_INCLUDED
