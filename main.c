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

    char quit;

    do
    {
        int index = registerLoginMenu(users, &totalUsers);
        if (users[index].isAdmin == 1)
        {
            quit = adminMenu(users, index, &totalUsers);
        }
        else
        {
            quit = userMenu(users, index, &totalUsers);
        }
    } while(quit != 27);


    saveFile(users, sizeof(stUser), totalUsers, USERS);

    return 0;
}
