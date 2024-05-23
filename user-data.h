#include "user.h"

void newEmail (stUser *users, int index);
int validEmail(char *email);
int existingEmail(char *email, stUser *users);
void getPass(char *pass);
int validPassword(char *pass);
int matchPassword(char *pass1, char *pass2);
