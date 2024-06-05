#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "menu.h"
#define USERS "Files/F_USERS.dat"


int main()
{
    setlocale(LC_ALL, "spanish");
//
//    stUser users[1000];
//    int totalUsers = readUserFile(users, USERS);
//
//    menu(users, registerLogin(users, &totalUsers));
//
//
//    saveUserFile(users, USERS, totalUsers);

    stComment comments[1000];
    int totalComments = readCommentFile(comments,F_COMMENTS);
    printf("total comentarios = %d\n", totalComments);
    for (int i = 0; i < totalComments; i++)
    {
        printComment(comments,i);
        printf("\n");
    }

    return 0;
}
