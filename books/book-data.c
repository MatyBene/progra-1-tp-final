#include "book-data.h"

void newTitle(stBook books[], int index) /// ESTABLECE UN NUEVO TITULO A UN LIBRO
{
    char aux[100];
    do
    {
        printf("Ingrese el título del libro: ");
        fflush(stdin);
        getString(aux, 100);
        system("cls");
        if(!isNotEmpty(aux))
        {
            printf("El campo no puede estar vacio.\n\n");
            newTitle(books, index);
        }
        else if(existingBook(aux, books, index))
        {
            printf("El titulo que quiere ingresar ya se encuentra cargado.\n");
            newTitle(books, index);
        }
        else
        {
            strcpy(books[index].title, aux);
        }
    }
    while(!isNotEmpty(aux) && existingBook(aux, books, index));
}

void newPublisher(stBook books[], int index) /// ESTABLECE UNA NUEVA EDITORIAL A UN LIBRO
{
    newField(books[index].publisher, "Ingrese la editorial: ", 50);
}

void newAuthor(stBook books[], int index) /// ESTABLECE UN NUEVO AUTOR PARA UN LIBRO
{
    newField(books[index].author, "Ingrese el autor: ", 50);
}

void newCategory(stBook books[], int index) /// ESTABLECE UNA NUEVA CATEGORIA PARA UN LIBRO
{
    newField(books[index].category, "Ingrese la categoría: ", 50);
}

int fisrtFreeIdBook(stBook books[], int totalBooks) /// ENCUENTRA EL PRIMER ID LIBRE EN EL ARREGLO DE LIBROS
{
    int i = 0;

    while (i < totalBooks && i == books[i].bookId-1)
    {
        i++;
    }

    return i+1;
}


