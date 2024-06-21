#include "book.h"
#include "book-data.h"
#include "../menu.h"
#include <ctype.h>
#include <unistd.h>

void bookRegister(stBook books[], int *index)
{
    books[*index].bookId = *index + 1;
    newTitle(books, *index);
    newPublisher(books, *index);
    newAuthor(books, *index);
    newCategory(books, *index);
    books[*index].rating = 0;
    books[*index].deleted = 0;
    (*index)++;
}

void printBookAdmin(const void *elements, int index)
{
    stBook *books = (stBook*) elements;

    printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
    printf("ID: ............. %d\n", books[index].bookId);
    printf("Titulo: ......... %s\n", books[index].title);
    printf("Editorial: ...... %s\n", books[index].publisher);
    printf("Autor: .......... %s\n", books[index].author);
    printf("Categoria: ...... %s\n", books[index].category);
    printf("Valoracion: ..... %.2f\n", books[index].rating);
    printf("Eliminado: ...... %s\n", books[index].deleted ? "Si" : "No");
}

void printBook(const void *elements, int index)
{
    stBook *books = (stBook*) elements;

    printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
    printf("\tTitulo: ......... %s\n", books[index].title);
    printf("\tCategoria: ...... %s\n", books[index].category);
    printf("\tValoracion: ..... %.2f\n\n", books[index].rating);
}

void printBookExtended(const void *elements, int index)
{
    stBook *books = (stBook*) elements;

    printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
    printf("\tTitulo: ......... %s\n", books[index].title);
    printf("\tEditorial: ...... %s\n", books[index].publisher);
    printf("\tAutor: .......... %s\n", books[index].author);
    printf("\tCategoria: ...... %s\n", books[index].category);
    printf("\tValoracion: ..... %.2f\n\n", books[index].rating);
    printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
}

int compareBookId(const void *a, const void *b)
{
    stBook *bookA = (stBook *) a;
    stBook *bookB = (stBook *) b;
    return (bookA->bookId - bookB->bookId);
}

int compareRating(const void *a, const void *b)
{
    int flag;
    stBook *bookA = (stBook *) a;
    stBook *bookB = (stBook *) b;

    if (bookA->rating < bookB->rating)
    {
        flag = 1;
    }
    else if (bookA->rating > bookB->rating)
    {
        flag = -1;
    }
    else
    {
        flag = 0;
    }
    return flag;
}

int compareTitle(const void *a, const void *b)
{
    stBook *bookA = (stBook *) a;
    stBook *bookB = (stBook *) b;

    return strcmp(bookA->title, bookB->title);
}

int compareCategory(const void *a, const void *b)
{
    stBook *bookA = (stBook *) a;
    stBook *bookB = (stBook *) b;

    return strcmp(bookA->category, bookB->category);
}

void searchBooks(int index, stBook books[], int totalBooks)
{
    char opcion ;

    do
    {
        printf("Seleccione como desea buscar libros: \n");
        printf("  1) Por titulo.\n");
        printf("  2) Por autor.\n");
        printf("  3) Por categoria.\n");
        printf("esc) Volver al menu.\n");

        fflush(stdin);
        opcion = getch();
        switch(opcion)
        {
        case 49:
            searchBooksByTitle(index, books, totalBooks);
            break;
        case 50:
            searchBooksByAuthor(index, books, totalBooks);
            break;
        case 51:
            searchBooksByCategory(index, books, totalBooks);
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
    }
    while(opcion != 49 && opcion != 50 && opcion != 51 && opcion != 27);
}

void toLowerCase(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower((unsigned char) str[i]);
    }
}

int matchTitleBook(stBook books[], int totalBooks, char searchTitle[], stBook foundBooks[], int totalFoundBooks)
{
    char lowerSearchTitle[100];
    char lowerTitle[100];

    strcpy(lowerSearchTitle, searchTitle);
    toLowerCase(lowerSearchTitle);

    for(int i = 0; i < totalBooks; i++)
    {
        strcpy(lowerTitle, books[i].title);
        toLowerCase(lowerTitle);

        if(strstr(lowerTitle, lowerSearchTitle) != NULL)
        {
            foundBooks[totalFoundBooks] = books[i];
            (totalFoundBooks)++;
        }
    }

    return totalFoundBooks;
}


int matchAuthorBook(stBook books[], int totalBooks, char searchAuthor[], stBook foundBooks[], int totalFoundBooks)
{
    char lowerSearchAuthor[100];
    char lowerAuthor[100];

    strcpy(lowerSearchAuthor, searchAuthor);
    toLowerCase(lowerSearchAuthor);

    for(int i = 0; i < totalBooks; i++)
    {
        strcpy(lowerAuthor, books[i].author);
        toLowerCase(lowerAuthor);

        if(strstr(lowerAuthor, lowerSearchAuthor) != NULL)
        {
            foundBooks[totalFoundBooks] = books[i];
            (totalFoundBooks)++;
        }
    }

    return totalFoundBooks;
}


int matchCategoryBook(stBook books[], int totalBooks, char searchCategory[], stBook foundBooks[], int totalFoundBooks)
{
    char lowerSearchCategory[100];
    char lowerCategory[100];

    strcpy(lowerSearchCategory, searchCategory);
    toLowerCase(lowerSearchCategory);

    for(int i = 0; i < totalBooks; i++)
    {
        strcpy(lowerCategory, books[i].category);
        toLowerCase(lowerCategory);

        if(strstr(lowerCategory, lowerSearchCategory) != NULL)
        {
            foundBooks[totalFoundBooks] = books[i];
            (totalFoundBooks)++;
        }
    }

    return totalFoundBooks;
}


void searchBooksBy(int index, stBook books[], int totalBooks, const char *prompt, MatchFunction matchFunc){
    char searchTerm[100];
    stBook foundBooks[1000];
    int totalFoundBooks = 0;

    system("cls");
    printf("%s\n", prompt);
    gets(searchTerm);

    totalFoundBooks = matchFunc(books, totalBooks, searchTerm, foundBooks, totalFoundBooks);

    if (totalFoundBooks == 0)
    {
        printf("No se encontro ningun libro con ese criterio.");
        // sleep(1);
    }
    else
    {
        paginated(index, foundBooks, &totalFoundBooks, 5, printBook, booksOptionMenu);
    }
}

void searchBooksByTitle(int index, stBook books[], int totalBooks)
{
    searchBooksBy(index, books, totalBooks, "Ingrese el titulo del libro:", matchTitleBook);
}

void searchBooksByAuthor(int index, stBook books[], int totalBooks)
{
    searchBooksBy(index, books, totalBooks, "Ingrese el autor:", matchAuthorBook);
}

void searchBooksByCategory(int index, stBook books[], int totalBooks)
{
    searchBooksBy(index, books, totalBooks, "Ingrese la categoria:", matchCategoryBook);
}
