#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "menu.h"
#define USERS "Files/F_USERS.dat"


int main()
{
    setlocale(LC_ALL, "spanish");

    stComment comments[1000];
    int totalComments = readCommentFile(comments,F_COMMENTS);


    saveCommentFile(comments,F_COMMENTS,totalComments);

    return 0;
}
