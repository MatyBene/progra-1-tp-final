#include "book.h"
#include "book-data.h"

void bookRegister(stBook books[], int *index){
    books[*index].bookId = *index;
    newTitle(books, *index);
    newPublisher(books, *index);
    newAuthor(books, *index);
    newCategory(books, *index);
    books[*index].rating = 0;
    books[*index].comments = 0;
    books[*index].deleted = 0;
    (*index)++;
}

void printBook(stBook books[], int index){
    printf("ID: ............. %d\n", books[index].bookId);
    printf("Titulo: ......... %s\n", books[index].title);
    printf("Editorial: ...... %s\n", books[index].publisher);
    printf("Autor: .......... %s\n", books[index].author);
    printf("Categoria: ...... %s\n", books[index].category);
    printf("Valoracion: ..... %.2f\n", books[index].rating);
    printf("Comentarios: .... %d\n", books[index].comments);
    printf("Eliminado: ... %s\n", books[index].deleted ? "Si" : "No");
    printf("\n><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
}
