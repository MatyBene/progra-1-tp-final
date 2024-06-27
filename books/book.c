#include "book.h"
#include "book-data.h"
#include "../menu.h"
#include <unistd.h>

void bookRegister(stBook books[], int *totalBooks) /// PERMITE REGISTRAR UN NUEVO LIBRO A LOS USUARIOS
{
    books[*totalBooks].bookId = fisrtFreeIdBook(books, *totalBooks);
    newTitle(books, *totalBooks);
    newPublisher(books, *totalBooks);
    newAuthor(books, *totalBooks);
    newCategory(books, *totalBooks);
    books[*totalBooks].rating = 0;
    books[*totalBooks].deleted = 0;

    appendFile(books, sizeof(stBook), *totalBooks, BOOKS);
    (*totalBooks)++;

}

void printBookAdmin(const void *elements, int index) /// MUESTRA EL LIBRO CON LOS DETALLES DEL ADMIN
{
    stBook *books = (stBook*) elements;
    if(books[index].deleted)
    {
        printf("\t\tDESACTIVADO\n\n");
    }

    printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
    printf("ID: ............. %d\n", books[index].bookId);
    printf("Titulo: ......... %s\n", books[index].title);
    printf("Editorial: ...... %s\n", books[index].publisher);
    printf("Autor: .......... %s\n", books[index].author);
    printf("Categoria: ...... %s\n", books[index].category);
    printf("Valoracion: ..... %.2f\n", books[index].rating);
    printf("Eliminado: ...... %s\n", books[index].deleted ? "Si" : "No");
    printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n");
}

void printBook(const void *elements, int index) /// MUESTRA LOS DATOS PRINCIPALES DE UN LIBRO
{
    stBook *books = (stBook*) elements;

    if(books[index].deleted)
    {
        printf("\t\tDESACTIVADO\n\n");
    }

    printf("\tTitulo: ......... %s\n", books[index].title);
    printf("\tCategoria: ...... %s\n", books[index].category);
    printf("\tValoracion: ..... %.2f\n\n", books[index].rating);
    printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n");
}

void printBookExtended(const void *elements, int index) /// MUESTRA LOS DETALLES DEL LIBRO
{
    stBook *books = (stBook*) elements;

    if(books[index].deleted)
    {
        printf("\t\tDESACTIVADO\n\n");
    }

    printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
    printf("\tTitulo: ......... %s\n", books[index].title);
    printf("\tEditorial: ...... %s\n", books[index].publisher);
    printf("\tAutor: .......... %s\n", books[index].author);
    printf("\tCategoria: ...... %s\n", books[index].category);
    printf("\tValoracion: ..... %.2f\n\n", books[index].rating);
    printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
}

int compareBookId(const void *a, const void *b) /// FUNCION DE COMPARACION USADA PARA QSORT
{
    stBook *bookA = (stBook *) a;
    stBook *bookB = (stBook *) b;
    return (bookA->bookId - bookB->bookId);
}

int compareRating(const void *a, const void *b) /// FUNCION DE COMPARACION USADA PARA QSORT
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

int compareTitle(const void *a, const void *b) /// FUNCION DE COMPARACION USADA PARA QSORT
{
    stBook *bookA = (stBook *) a;
    stBook *bookB = (stBook *) b;

    return strcmp(bookA->title, bookB->title);
}

int compareCategory(const void *a, const void *b) /// FUNCION DE COMPARACION USADA PARA QSORT
{
    stBook *bookA = (stBook *) a;
    stBook *bookB = (stBook *) b;

    return strcmp(bookA->category, bookB->category);
}

void toLowerCase(char *str) /// CONVIERTE UN STRING A MINUSCULAS
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower((unsigned char) str[i]);
    }
}

int matchTitleBook(stBook books[], int totalBooks, char searchTitle[], stBook foundBooks[], int totalFoundBooks)
{
    /// VERIFICA LA COINCIDENCIA DE UN TEXTO CON UN TITULO Y DEVUELVE LA CANTIDAD ENCONTRADA

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
    /// VERIFICA LA COINCIDENCIA DE UN TEXTO CON UN AUTOR Y DEVUELVE LA CANTIDAD ENCONTRADA

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
    /// VERIFICA LA COINCIDENCIA DE UN TEXTO CON UNA CATEGORIA Y DEVUELVE LA CANTIDAD ENCONTRADA

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

void searchBooksBy(int index, stBook books[], int totalBooks, const char *prompt, MatchFunction matchFunc)
{
    /// FUNCION GENERICA PARA BUSCAR LIBROS SEGUN PARAMETRO

    char searchTerm[100];
    stBook foundBooks[1000];
    int totalFoundBooks = 0;

    system("cls");
    printf("%s\n", prompt);
    getString(searchTerm, 100);

    totalFoundBooks = matchFunc(books, totalBooks, searchTerm, foundBooks, totalFoundBooks);

    if (totalFoundBooks == 0)
    {
        printf("No se encontro ning�n libro con ese criterio.");
        sleep(1);
    }
    else
    {
        paginated(index, foundBooks, &totalFoundBooks, 5, printBook, bookHandleMenu);
    }
}

void searchBooksByTitle(int index, stBook books[], int totalBooks) /// BUSCA LIBROS POR TITULO
{
    searchBooksBy(index, books, totalBooks, "Ingrese el titulo del libro:", matchTitleBook);
}

void searchBooksByAuthor(int index, stBook books[], int totalBooks) /// BUSCA LIBROS POR AUTOR
{
    searchBooksBy(index, books, totalBooks, "Ingrese el autor:", matchAuthorBook);
}

void searchBooksByCategory(int index, stBook books[], int totalBooks) /// BUSCA LIBROS POR CATEGORIA
{
    searchBooksBy(index, books, totalBooks, "Ingrese la categoria:", matchCategoryBook);
}

int searchIndexBookById(int idBook, stBook books[], int totalBooks) /// DEVUELVE LA POSICION DE UN LIBRO A PARTIR DE SU ID
{
    int indexBook = -1;
    int i = 0;

    while(indexBook == -1 && i < totalBooks)
    {
        if(idBook == books[i].bookId)
        {
            indexBook = i;
        }
        i++;
    }

    return indexBook;
}

void favBooks(int favorites[], int numFavorites, stBook books[], int totalBooks, stBook favs[]) /// CREA UN ARREGLO CON LOS LIBROS FAVORITOS
{
    for(int i = 0; i < numFavorites; i++)
    {
        int flag = 0;
        int j = 0;

        while(j < totalBooks && flag == 0)
        {
            if(books[j].bookId == favorites[i])
            {
                favs[i] = books[j];
                flag = 1;
            }
            j++;
        }
    }
}

void activateBook(int idBook, stBook books[], int *totalBooks) /// ACTIVA UN LIBRO
{
    int indexBook = searchIndexBookById(idBook, books, *totalBooks);
    if(books[indexBook].deleted)
    {
        books[indexBook].deleted = 0;
    }
}

void disableBook(int idBook, stBook books[], int *totalBooks) /// DESACTIVA UN LIBRO
{
    int indexBook = searchIndexBookById(idBook, books, *totalBooks);
    if(!books[indexBook].deleted)
    {
        books[indexBook].deleted = 1;
    }
}

void deleteBook(int idBook, stBook books[], int *totalBooks) /// BORRA UN LIBRO PERMANENTEMENTE
{
    int indexBook = searchIndexBookById(idBook, books, *totalBooks);
    deleteFile(books, sizeof(stBook), indexBook, *totalBooks, BOOKS);
    *totalBooks = readFile(books, sizeof(stBook), BOOKS);
}


