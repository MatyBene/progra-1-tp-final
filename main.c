#include <locale.h>
#include "menu.h"
#include "Files/files.h"
#include "Users/user.h"
#define USERS "Files/F_USERS.dat"


int main()
{
    setlocale(LC_ALL, "spanish");

    stUser users[1000];
    int totalUsers = readFile(users, sizeof(stUser), USERS);
    stBook books[1000];
    int totalBooks = readFile(books, sizeof(stBook), F_BOOKS);
    stComment comments[1000];
    int totalComments = readFile(comments, sizeof(stComment), F_COMMENTS);

    char quit;

    do
    {
        int index = registerLoginMenu(users, &totalUsers);
        if (users[index].isAdmin == 1)
        {
            quit = adminMenu(users, index, &totalUsers, books, &totalBooks);
        }
        else
        {
            quit = userMenu(users, index, &totalUsers, books, &totalBooks);
        }
    } while(quit != 27);


    saveFile(users, sizeof(stUser), totalUsers, USERS, compareUserId);
    saveFile(books, sizeof(stBook), totalBooks, F_BOOKS, compareBookId);

    return 0;
}
