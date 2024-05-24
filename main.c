#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "menu.h"

int main()
{
    setlocale(LC_ALL, "spanish");

    menu();

    return 0;
}
