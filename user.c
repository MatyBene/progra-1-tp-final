#include "user-data.h"
#include "user.h"

void userRegister(stUser *users, int index) // registro de usuarios
{
    users[index].userId = index;
    users[index].isAdmin = 0;
    users[index].deleted = 0;
    newEmail(users, index);
    newPassword(users, index);
    newUserName(users, index);
    newAdress(users, index);
    newGender(users, index);
    newBirthDate(users, index);
    newDni(users, index);
    index++;

}

