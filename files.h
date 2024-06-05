#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Users/user.h"
#include "Comments/coment.h"
int readUserFile (stUser *users, char *fileName);
void saveUserFile (stUser *users, char *fileName, int totalUsers);
int readCommentFile (stComment *comments, char *fileName);
void saveCommentFile (stComment *comments, char *fileName, int totalComments);
#endif // FILES_H_INCLUDED
