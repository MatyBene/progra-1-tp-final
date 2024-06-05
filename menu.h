#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "menu.h"
#include "Users/user.h"
#include "files.h"
#include "Comments/coment-data.h"
#include "Comments/coment.h"

void menu(stUser *users, int index);
int registerLogin(stUser *users, int *index);



#endif // MENU_H_INCLUDED
