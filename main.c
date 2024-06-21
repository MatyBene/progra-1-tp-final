#include <locale.h>
#include "menu.h"
#include "Files/files.h"
#include "Users/user.h"


int main()
{
    setlocale(LC_ALL, "spanish");

    run();

    return 0;
}
