#include "user-data.h"
#include "user.h"

void userRegister(stUser *users, int index) // registro de usuarios
{

    newEmail(users, index);
    newPassword(users, index);
    userName(users, index);


}

