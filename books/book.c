#include "book.h"
#include "book-data.h"


void bookRegister(stBook books[], int *index){
    books[*index].bookId = *index + 1;
    newTitle(books, *index);
    newPublisher(books, *index);
    newAuthor(books, *index);
    newCategory(books, *index);
    books[*index].rating = 0;
    books[*index].deleted = 0;
    (*index)++;
}

void printBookAdmin(const void elements[], int index){
    stBook books[] = (stBook*) elements;

    printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
    printf("ID: ............. %d\n", books[index].bookId);
    printf("Titulo: ......... %s\n", books[index].title);
    printf("Editorial: ...... %s\n", books[index].publisher);
    printf("Autor: .......... %s\n", books[index].author);
    printf("Categoria: ...... %s\n", books[index].category);
    printf("Valoracion: ..... %.2f\n", books[index].rating);
    printf("Eliminado: ...... %s\n", books[index].deleted ? "Si" : "No");
}

void printBook(const void elements[], int index){
    stBook books[] = (stBook*) elements;

    printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
    printf("\tTitulo: ......... %s\n", books[index].title);
    printf("\tCategoria: ...... %s\n", books[index].category);
    printf("\tValoracion: ..... %.2f\n\n", books[index].rating);
}

void printBookExtended(const void elements[], int index){
    stBook books[] = (stBook*) elements;

    printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
    printf("\tTitulo: ......... %s\n", books[index].title);
    printf("\tEditorial: ...... %s\n", books[index].publisher);
    printf("\tAutor: .......... %s\n", books[index].author);
    printf("\tCategoria: ...... %s\n", books[index].category);
    printf("\tValoracion: ..... %.2f\n\n", books[index].rating);
    printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
}

void sortBooks(stBook books[], int totalBooks){
    char opcion ;

    do{
        printf("Seleccione como desea ver ordenados los libros: \n");
        printf("1) Por valoraci�n.\n");
        printf("2) Por categor�a.\n");
        printf("3) Por orden alfab�tico.\n");
        printf("esc) Volver al menu.\n");

        fflush(stdin);
        opcion = getch();
        switch(opcion){
            case 49:
                qsort(books, totalBooks, sizeof(stBook), compareRating);
                paginated(books, totalBooks);
                break;
            case 50:
                qsort(books, totalBooks, sizeof(stBook), compareCategory);
                paginated(books, totalBooks);
                break;
            case 51:
                qsort(books, totalBooks, sizeof(stBook), compareTitle);
                paginated(books, totalBooks);
                break;
            case 27:
                system("cls");
                break;
            default:
                system("cls");
                printf("La opcion ingresada no es valida.");
//                sleep(1);
                system("cls");
                break;
        }
    } while(opcion != 49 && opcion != 50 && opcion != 51 && opcion != 27);
}

int compareBookId(const void *a, const void *b){
    stBook *bookA = (stBook *) a;
    stBook *bookB = (stBook *) b;
    return (bookA->bookId - bookB->bookId);
}

int compareRating(const void *a, const void *b){
    int flag;
    stBook *bookA = (stBook *) a;
    stBook *bookB = (stBook *) b;

    if (bookA->rating < bookB->rating){
            flag = 1;
        } else if (bookA->rating > bookB->rating){
            flag = -1;
        } else {
            flag = 0;
        }
    return flag;
}

int compareTitle(const void *a, const void *b){
    stBook *bookA = (stBook *) a;
    stBook *bookB = (stBook *) b;

    return strcmp(bookA->title, bookB->title);
}

int compareCategory(const void *a, const void *b){
    stBook *bookA = (stBook *) a;
    stBook *bookB = (stBook *) b;

    return strcmp(bookA->category, bookB->category);
}

void searchBooks(stBook books[], int totalBooks){
    char opcion ;

    do{
        printf("Seleccione como desea buscar libros: \n");
        printf("  1) Por titulo.\n");
        printf("  2) Por autor.\n");
        printf("  3) Por categoria.\n");
        printf("esc) Volver al menu.\n");

        fflush(stdin);
        opcion = getch();
        switch(opcion){
            case 49:
                searchBooksByTitle(books, totalBooks);
                break;
            case 50:
                searchBooksByAuthor(books, totalBooks);
                break;
            case 51:
                printf("BUSCAR POR CATEGORIA\n");
                system("pause");
                /// searchBookByCategory(books, totalBooks);
                break;
            case 27:
                system("cls");
                break;
            default:
                system("cls");
                printf("La opcion ingresada no es valida.");
//                sleep(1);
                system("cls");
                break;
        }
    } while(opcion != 49 && opcion != 50 && opcion != 51 && opcion != 27);
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

int matchTitleBook(stBook books[], int totalBooks, char searchTitle[], stBook foundBooks[], int totalFoundBooks){
    char lowerSearchTitle[100];
    char lowerTitle[100];

    strcpy(lowerSearchTitle, searchTitle);
    toLowerCase(lowerSearchTitle);

    for(int i = 0; i < totalBooks; i++){
        strcpy(lowerTitle, books[i].title);
        toLowerCase(lowerTitle);

        if(strstr(lowerTitle, lowerSearchTitle) != NULL){
            foundBooks[totalFoundBooks] = books[i];
            (totalFoundBooks)++;
        }
    }

    return totalFoundBooks;
}

void searchBooksByTitle(stBook books[], int totalBooks){
    char searchTitle[100];
    stBook foundBooks[1000];
    int totalFoundBooks = 0;

    system("cls");
    printf("Ingrese el titulo del libro: \n");
    gets(searchTitle);

    totalFoundBooks = matchTitleBook(books, totalBooks, searchTitle, foundBooks, totalFoundBooks);

    if(totalFoundBooks == 0){
        printf("No se encontro ningun libro con ese titulo.");
//        sleep(1);
    } else {
        paginated(foundBooks, totalFoundBooks);
    }
}

int matchAuthorBook(stBook books[], int totalBooks, char searchAuthor[], stBook foundBooks[], int totalFoundBooks){
    char lowerSearchAuthor[100];
    char lowerAuthor[100];

    strcpy(lowerSearchAuthor, searchAuthor);
    toLowerCase(lowerSearchAuthor);

    for(int i = 0; i < totalBooks; i++){
        strcpy(lowerAuthor, books[i].author);
        toLowerCase(lowerAuthor);

        if(strstr(lowerAuthor, lowerSearchAuthor) != NULL){
            foundBooks[totalFoundBooks] = books[i];
            (totalFoundBooks)++;
        }
    }

    return totalFoundBooks;
}

void searchBooksByAuthor(stBook books[], int totalBooks){
    char searchAuthor[100];
    stBook foundBooks[1000];
    int totalFoundBooks = 0;

    system("cls");
    printf("Ingrese el autor: \n");
    gets(searchAuthor);

    totalFoundBooks = matchAuthorBook(books, totalBooks, searchAuthor, foundBooks, totalFoundBooks);

    if(totalFoundBooks == 0){
        printf("No se encontro ningun libro con ese autor.");
//        sleep(1);
    } else {
        paginated(foundBooks, totalFoundBooks);
    }
}

