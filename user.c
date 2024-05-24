#include "user-data.h"
#include "user.h"

void userRegister(stUser *users, int index) // registro de usuarios
{
    users[index].userId = index;
    newEmail(users, index);
    newPassword(users, index);
    newUserName(users, index);
    newAdress(users, index);
    newGender(users, index);


    index++;

}

