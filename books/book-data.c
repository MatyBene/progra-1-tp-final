#include "book-data.h

/* --VALIDACIONES-- */

int isNotEmpty(char field[]){
    return strlen(field) > 0;
}

int existingBook(char title[], stBook books[], int index){
    int i = 0;
    int flag = 0;

    while (i < index && flag == 0)
    {
        if (strcmpi(books[i].title, title) == 0)
        {
            flag = 1;
        }
        i++;
    }

    return flag;
}
/* --VALIDACIONES-- */

