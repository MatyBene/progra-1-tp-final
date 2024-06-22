#include "menu.h"
#include <unistd.h>


/* >>>>>>>>>>>>>>>>>>>GLOBAL<<<<<<<<<<<<<<<<<<<<< */

stUser users[1000];
stBook books[1000];
stComment comments[1000];
int totalUsers;
int totalBooks;
int totalComments;

/* >>>>>>>>>>>>>>>>>>>GLOBAL<<<<<<<<<<<<<<<<<<<<< */

void run() /// INICIA LA APLICACION
{
    readDataMenu();

//    char quit;
//
//    do
//    {
//        int index = registerLoginMenu();
//        if (users[index].isAdmin == 1)
//        {
//            quit = adminMenu(index);
//        }
//        else
//        {
//            quit = userMenu(index);
//        }
//    }
//    while(quit != 27);
    userMenu(100);
    saveDataMenu();
}

void readDataMenu()
{
    totalUsers = readFile(users, sizeof(stUser), USERS);
    totalBooks = readFile(books, sizeof(stBook), BOOKS);
    totalComments = readFile(comments, sizeof(stComment), COMMENTS);
}

void saveDataMenu()
{
    saveFile(users, sizeof(stUser), totalUsers, USERS, compareUserId);
    saveFile(books, sizeof(stBook), totalBooks, BOOKS, compareBookId);
    saveFile(comments, sizeof(stComment), totalComments, COMMENTS, compareCommentId);
}

char userMenu(int index)
{
    char option;

    do
    {
        system("cls");
        printf("MENU PRINCIPAL\n\n");
        printf("  0)  Cerrar sesion.\n");
        printf("  1)  Perfil.\n");
        printf("  2)  Editar informacion personal.\n");
        printf("  3)  Ver listado de libros.\n");
        printf("  4)  Ver libros favoritos.\n");
        printf("  5)  Buscar libro.\n");
        printf("  6)  Agregar un libro.\n");
        printf("  7)  Eliminar cuenta.\n");
        if (users[index].isAdmin == 1)
        {
            printf("  8)  Menu admin\n");
        }
        printf("esc)  Salir.\n");

        fflush(stdin);
        option = getch();

        switch(option)
        {
            case '0':
            {
                system("cls");
                break;
            }
            case '1':
            {
                system("cls");
                printUser(users, index);
                system("pause");
                break;
            }
            case '2':
            {
                userInfoMenu(index);
                break;
            }
            case '3':
            {
                system("cls");
                sortBooksMenu(index, books, &totalBooks);
                break;
            }
            case '4':
            {
                system("cls");
                if(users[index].numFavorites != 0){
                    stBook favs[1000];
                    favBooks(users[index].favoriteBooks, users[index].numFavorites, books, totalBooks, favs);
                    sortBooksMenu(index, favs, &users[index].numFavorites);
                } else {
                    printf("No tiene libros en la lista de favoritos.");
                    sleep(1);
                }
                break;
            }
            case '5':
            {
                system("cls");
                searchBooks(index, books, totalBooks);
                break;
            }
            case '6':
            {
                system("cls");
                bookRegister(books, &totalBooks);
                break;
            }
            case '7':
            {
                printf("Deseas eliminar tu cuenta %s? (y/n)\n", users[index].username);
                if(yesNo())
                {
                    deleteUser(users, index, &totalUsers);
                    system("pause");
                    system("cls");
                    option = '0';
                }
                else
                {
                    printf("No se elimino la cuenta.");
                    system("pause");
                }
                break;
            }
            case '8':
            {
                system("cls");
                if(!users[index].isAdmin)
                {
                    option = 1;
                }
                break;
            }
            case 27:
            {
                system("cls");
                break;
            }
        }
    }
    while (option != '0' && option != 27 && option != '8');

    return option;

}

void userInfoMenu (int index)
{
    char option;

    do
    {
        system("cls");
        printf("INFORMACION PERSONAL\n\n");

        printf("  1)  Editar Email.\n");
        printf("  2)  Editar Contrase�a.\n");
        printf("  3)  Editar Nombre de Usuario.\n");
        printf("  4)  Editar Genero (?.\n");
        printf("  5)  Editar Fecha de Nacimiento.\n");
        printf("  6)  Editar Libros Favoritos.\n");
        printf("  7)  Editar DNI.\n");
        printf("  8)  Editar Direccion.\n");
        printf("esc)  Volver.\n");

        fflush(stdin);
        option = getch();

        switch(option)
        {
        case 27:
        {
            system("cls");
            break;
        }
        case '1':
        {
            system("cls");
            newEmail(users, index);
            printf("El mail ha sido actualizado a %s\n", users[index].email);
            system("pause");
            break;
        }
        case '2':
        {
            system("cls");
            newPassword(users, index);
            printf("La contrase�a ha sido actualizada\n");
            system("pause");
            break;
        }
        case '3':
        {
            system("cls");
            newUserName(users, index);
            printf("El nombre de usuario ha sido actualizado a %s\n", users[index].username);
            system("pause");
            break;
        }
        case '4':
        {
            system("cls");
            newGender(users, index);
            printf("El genero ha sido actualizado a %c\n", users[index].gender);
            system("pause");
            break;
        }
        case '5':
        {
            system("cls");
            newBirthDate(users, index);
            printf("La fecha de nacimiento ha sido actualizada a %s\n", users[index].birthDate);
            system("pause");
            break;
        }
        case '6':
        {

            break;
        }
        case '7':
        {
            system("cls");
            newDni(users, index);
            printf("El DNI ha sido actualizado a %s\n", users[index].dni);
            system("pause");
            break;
        }
        case '8':
        {
            system("cls");
            newAdress(users, index);
            printf("La direccion ha sido actualizada\n");
            system("pause");
            break;
        }
        }
    }
    while(option != 27);
}

char adminMenu(int index)
{
    char option;

    do
    {
        system("cls");
        printf("MENU ADMIN\n\n");
        printf("  0)  Cerrar sesion.\n");
        printf("  1)  Dashboard.\n");
        printf("  2)  Buscar libro.\n");
        printf("  3)  Buscar usuario.\n");
        printf("  4)  Ir al menu de usuario.\n");
        printf("esc)  Salir.\n");

        fflush(stdin);
        option = getch();

        switch(option)
        {
        case '0':
        {
            system("cls");
            break;
        }
        case '1':
        {
            /// DASHBOARD
            break;
        }
        case '2':
        {
            /// BUSCAR LIBRO
            break;
        }
        case '3':
        {
            /// BUSCAR USUARIO
            break;
        }
        case '4':
        {
            system("cls");
            option = userMenu(index);
            break;
        }
        case 27:
        {
            system("cls");
            break;
        }
        }

    }
    while (option != '0' && option != 27);

    return option;
}

void dashboardMenu()
{
    char option;

    do
    {
        system("cls");
        printf("DASHBOARD \n\n");
        printf("  1)  Ver Usuarios (%d)\n", totalUsers);
        printf("  2)  Ver Libros (%d)\n", totalBooks);
        printf("  3)  Ver Comentarios (%d)\n", totalComments);
        printf("  4)  Ver ultimo Usuario registrado.\n");
        printf("  5)  Ver ultimo Libro registrado.\n");
        printf("esc)  Salir.\n");

        fflush(stdin);
        option = getch();

        switch(option)
        {
        case '1':
        {
            /// VER USUARIOS
            system("cls");

            break;
        }
        case '2':
        {
            /// VER LIBROS
            break;
        }
        case '3':
        {
            /// VER COMENTARIOS
            break;
        }
        case '4':
        {
            /// VER ULTIMO USUARIO

            break;
        }
        case '5':
        {
            /// VER ULTIMO LIBRO

            break;
        }
        case 27:
        {
            /// SALIR
            system("cls");
            break;
        }
        }

    }
    while (option != 27);
}

int registerLoginMenu()
{
    char option[9];
    int index = -1;

    while(index == -1)
    {
        printf("Ingrese la accion que desea realizar: (Registrar/Ingresar)\n");
        fflush(stdin);
        gets(option);

        if (strcmpi(option,"registrar") == 0)
        {
            system("cls");
            userRegister(users, &totalUsers);
            index = userLogin(users, totalUsers);
        }
        else if (strcmpi(option,"ingresar") == 0)
        {
            system("cls");
            index = userLogin(users, totalUsers);
        }
        else
        {
            system("cls");
            printf("La opcion seleccionada no se reconoce.\n");
            index = -1;
        }
    }

    return index;
}

void actionUserMenu(char *prompt, actionFunction action)
{
    int id, index;

    printf("Seleccione el ID del usuario a %s: \n", prompt);
    scanf("%d", &id);
    index = matchId(users, id, totalUsers);
    if(index != -1)
    {
        printf("Desea %s al usuario %s? (y/n)\n", prompt, users[index].username);

        if (yesNo() && !users[index].isAdmin)
        {
            action(users, index, &totalUsers);
        }
        else
        {
            printf("No se pudo %s al usuario.\n", prompt);
        }
    }
    else
    {
        printf("El usuario no es valido.\n");
    }

    system("pause");
}

void paginated(int index, void *elements, int *totalElements, int pageSize, printFunction printElement, elementMenu handleMenu)
{
    int currentPage = 1;

    while(currentPage >= 1)
    {
        system("cls");
        displayPage(elements, *totalElements, currentPage, pageSize, printElement);
        printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
        printf("~ %d ~\n", currentPage);
        currentPage = handleUserInput(index, elements, totalElements, currentPage, handleMenu);
    }
}

void displayPage(const void *elements, int totalElements, int page, int pageSize, printFunction printElement)
{
    int start = (page - 1) * pageSize;
    int end = start + pageSize;

    if (end > totalElements)
    {
        end = totalElements;
    }

    for (int i = start; i < end; i++)
    {
        printf(" %d.", i - start + 1);
        printElement(elements, i);
    }
}

int handleUserInput(int index, void *elements, int *totalElements, int currentPage, elementMenu handleMenu)
{
    fflush(stdin);
    char key = getch();

    if(key == -32)
    {
        fflush(stdin);
        key = getch();

        switch (key)
        {
            case 77:
                if (currentPage * 5 < *totalElements)
                {
                    currentPage++;
                }
                break;
            case 75:
                if (currentPage > 1)
                {
                    currentPage--;
                }
                break;
        }
    }
    else if(key >= 49 && key <= 53)
    {
        handleMenu(index, (((currentPage - 1) * 5) + (int) key - 49), books, &totalBooks); /// los dos ultimos parametros mande eso, total no se usan. Si no no podia usar la funcion
    }
    else if(key == 27)
    {
        return -1;
    }
    else
    {
        handleUserInput(index, elements, totalElements, currentPage, handleMenu);
    }

    return currentPage;
}

void booksHandleMenu(int index, int bookIndex, void *elements, int *totalElements){
    stBook *handleBooks = (stBook *) elements;

    if(isNotEmpty(handleBooks[bookIndex].title)){
        char option;

        do{
            system("cls");
            printBookExtended(handleBooks, bookIndex);

            printf("\n\n");
            printf("  1)  %s favoritos.\n", isFavorite(users[index], handleBooks[bookIndex].bookId) ? "Quitar de" : "Agregar a");
            printf("  2)  Agregar comentario.\n");
            printf("  3)  Ver comentarios.\n");
            if (users[index].isAdmin == 1){
                printf("  4)  Modificar libro.\n");
                printf("  5)  Desabilitar libro.\n");
                printf("  6)  Eliminar libro.\n");
            }
            printf("esc)  Salir.\n");

            fflush(stdin);
            option = getch();

            switch(option){
                case '1':
                    system("cls");

                    if(isFavorite(users[index], handleBooks[bookIndex].bookId)){
                        removeFavorite(users, index, handleBooks[bookIndex].bookId);
                    } else {
                        addFavorite(users, index, handleBooks[bookIndex].bookId);
                    }
                    printf("Se %s favoritos", isFavorite(users[index], handleBooks[bookIndex].bookId) ? "agrego el libro a" : "quito el libro de");

                    break;
                case '2':
                    break;
                case '3':
                    break;
                case '4':
                    editBook(books, bookIndex);
                    break;
                case '5':
                    break;
                case '6':
                    break;

                case 27:
                    system("cls");
                    break;
            }


        } while(option != 27);
    }
}

void usersOptionMenu(void *elements, int index)
{

}

void commentsOptionMenu(void *elements, int index)
{

}

void sortBooksMenu(int index, void *elements, int *totalElements){
    stBook *arrBooks = (stBook *) elements;
    char opcion ;

    do{
        printf("Seleccione como desea ver ordenados los libros: \n");
        printf("  1) Por valoracion.\n");
        printf("  2) Por categoria.\n");
        printf("  3) Por orden alfabetico.\n");
        printf("esc) Volver al menu.\n");

        fflush(stdin);
        opcion = getch();
        switch(opcion){
            case '1':
                qsort(arrBooks, *totalElements, sizeof(stBook), compareRating);
                paginated(index, arrBooks, totalElements, 5, printBook, booksHandleMenu);
                break;

            case '2':
                qsort(arrBooks, *totalElements, sizeof(stBook), compareCategory);
                paginated(index, arrBooks, totalElements, 5, printBook, booksHandleMenu);
                break;

            case '3':
                qsort(arrBooks, *totalElements, sizeof(stBook), compareTitle);
                paginated(index, arrBooks, totalElements, 5, printBook, booksHandleMenu);
                break;

            case 27:
                system("cls");
                break;

            default:
                system("cls");
                printf("La opcion ingresada no es valida.");
                sleep(1);
                system("cls");
                break;
        }
    } while(opcion != '1' && opcion != '2' && opcion != '3' && opcion != 27);
}


