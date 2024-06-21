#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#define BOOKS "Files/F_BOOKS.dat"

typedef struct{
    int bookId; /// único, autoincremental
    char title[100];
    char publisher[50];
    char author[50];
    char category[50];
    float rating;
    int deleted; /// 0 si está activo - 1 si está eliminado
}stBook;

void bookRegister(stBook books[], int *index);
void printBookAdmin(stBook books[], int index);
void printBook(stBook books[], int index);
void printBookExtended(stBook books[], int index);
void displayPage(stBook books[], int totalBooks, int page, int pageSize);
int handleUserInput(int currentPage, stBook books[], int totalBooks);
void paginated(stBook books[], int totalBooks);
void sortBooks(stBook books[], int totalBooks);
int compareBookId(const void *a, const void *b);
int compareRating(const void *a, const void *b);
int compareTitle(const void *a, const void *b);
int compareCategory(const void *a, const void *b);
void searchBooks(stBook books[], int totalBooks);
void toLowerCase(char *str);
int matchTitleBook(stBook books[], int totalBooks, char searchTitle[], stBook foundBooks[], int totalFoundBooks);
void searchBooksByTitle(stBook books[], int totalBooks);
int matchAuthorBook(stBook books[], int totalBooks, char searchAuthor[], stBook foundBooks[], int totalFoundBooks);
void searchBooksByAuthor(stBook books[], int totalBooks);

#endif // BOOK_H_INCLUDED
