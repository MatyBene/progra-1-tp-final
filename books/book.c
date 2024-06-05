#include "book.h"
#include "book-data.h"

void bookRegister(stBook books[], int *index){
    books[*index].bookId = *index + 1;
    newTitle(books, *index);
    newPublisher(books, *index);
    newAuthor(books, *index);
    newCategory(books, *index);
    books[*index].rating = 0;
    books[*index].comments = 0;
    books[*index].deleted = 0;
    (*index)++;
}

void printBookAdmin(stBook books[], int index){
    printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
    printf("ID: ............. %d\n", books[index].bookId);
    printf("Titulo: ......... %s\n", books[index].title);
    printf("Editorial: ...... %s\n", books[index].publisher);
    printf("Autor: .......... %s\n", books[index].author);
    printf("Categoria: ...... %s\n", books[index].category);
    printf("Valoracion: ..... %.2f\n", books[index].rating);
    printf("Comentarios: .... %d\n", books[index].comments);
    printf("Eliminado: ...... %s\n", books[index].deleted ? "Si" : "No");
}

void printBook(stBook books[], int index){
    printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
    printf("\tTitulo: ......... %s\n", books[index].title);
    printf("\tCategoria: ...... %s\n", books[index].category);
    printf("\tValoracion: ..... %.2f\n\n", books[index].rating);
}

void printBookExtended(stBook books[], int index){
    printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
    printf("\tTitulo: ......... %s\n", books[index].title);
    printf("\tEditorial: ...... %s\n", books[index].publisher);
    printf("\tAutor: .......... %s\n", books[index].author);
    printf("\tCategoria: ...... %s\n", books[index].category);
    printf("\tValoracion: ..... %.2f\n", books[index].rating);
    printf("\tComentarios: .... %d\n\n", books[index].comments);
    printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
}

/* >>>>>>>>>>>>>>>>>>>UTILITIES<<<<<<<<<<<<<<<<<<<<< */

void displayPage(stBook books[], int totalBooks, int page, int pageSize) {
    int j = 0;
    int start = page * pageSize;
    int end = start + pageSize;

    if (end > totalBooks) {
        end = totalBooks;
    }

    for (int i = start; i < end; i++) {
        printf(" %d.", j + 1);
        printBook(books, i);
        j++;
    }
}

int handleUserInput(int currentPage, stBook books[], int totalBooks) {
    fflush(stdin);
    char key = getch();

        if(key == -32){
                fflush(stdin);
            key = getch();

            switch (key) {
                case 77:
                    if ((currentPage + 1) * 5 < totalBooks) {
                        currentPage++;
                    }
                    break;
                case 75:
                    if (currentPage > 0) {
                        currentPage--;
                    }
                    break;
                default:
                    printf("Opcion no valida.");
                    break;
            }
        }else if(key >= 49 && key <= 53){
                system("cls");
                printBookExtended(books, (currentPage * 5) + (int) key - 49);
                system("pause");
        }else if(key == 27){
            return -1;
        } else {
            handleUserInput(currentPage, books, totalBooks);
        }

//    else {
//        switch()
//    }

    return currentPage;
}

void paginated(stBook books[], int totalBooks){
    int currentPage = 0;

    while(currentPage >= 0){
        system("cls");
        displayPage(books, totalBooks, currentPage, 5);
        printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
        printf("~%d~\n", currentPage + 1);
        printf("Ingrese el numero del libro que desea ver en detalle: ");
        currentPage = handleUserInput(currentPage, books, totalBooks);

    }
}



/* >>>>>>>>>>>>>>>>>>>UTILITIES<<<<<<<<<<<<<<<<<<<<< */

