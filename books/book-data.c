#include "book-data.h"

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

void newTitle(stBook books[], int index){
    char aux[30];
    do{
        printf("Ingrese el t�tulo del libro: ");
        fflush(stdin);
        gets(aux);
        system("cls");
        if(!isNotEmpty(aux)){
            printf("El campo no puede estar vacio.\n\n");
            newTitle(books, index);
        } else if(existingBook(aux, books, index)){
            printf("El titulo que quiere ingresar ya se encuentra cargado.\n");
            newTitle(books, index);
        } else {
            strcpy(books[index].title, aux);
        }
    } while(!isNotEmpty(aux) && existingBook(aux, books, index));
}

void newField(char field[], char prompt[]){

    do{
        printf("%s", prompt);
        fflush(stdin);
        gets(field);
        system("cls");
        if(!isNotEmpty(field)){
            printf("El campo no puede estar vacio.\n\n");
        }
    } while(!isNotEmpty(field));
}

void newPublisher(stBook books[], int index){
    newField(books[index].publisher, "Ingrese la editorial: ");
}

void newAuthor(stBook books[], int index){
    newField(books[index].author, "Ingrese el autor: ");
}

void newCategory(stBook books[], int index){
    newField(books[index].category, "Ingrese la categor�a: ");
}

