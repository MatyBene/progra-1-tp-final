#include "user.h"

void getPass(char *pass);
void newEmail (stUser *users, int index);
void newPassword(stUser *users, int index);
void userName (stUser *users, int index);
int validEmail(char *email);
int existingEmail(char *email, stUser *users, int index);
int validPassword(char *pass);
int matchPassword(char *pass1, char *pass2);
int validUserName(char *uName, stUser *users, int index);
