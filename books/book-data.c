#include "book-data.h"

void newTitle(stBook books[], int index){
    char aux[30];
    do{
        printf("Ingrese el título del libro: ");
        fflush(stdin);
        getString(aux, 30);
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

void newPublisher(stBook books[], int index){
    newField(books[index].publisher, "Ingrese la editorial: ");
}

void newAuthor(stBook books[], int index){
    newField(books[index].author, "Ingrese el autor: ");
}

void newCategory(stBook books[], int index){
    newField(books[index].category, "Ingrese la categoría: ");
}


