#include "menu.h"


/* >>>>>>>>>>>>>>>>>>>GLOBAL<<<<<<<<<<<<<<<<<<<<< */

stUser users[1000];
stBook books[1000];
stComment comments[1000];
int totalUsers;
int totalBooks;
int totalComments;

/* >>>>>>>>>>>>>>>>>>>GLOBAL<<<<<<<<<<<<<<<<<<<<< */


/* >>>>>>>>>>>>>>>>>>>DATA<<<<<<<<<<<<<<<<<<<<< */

void readDataMenu() /// CARGA LOS DATOS DESDE LOS ARCHIVOS
{
    totalUsers = readFile(users, sizeof(stUser), USERS);
    totalBooks = readFile(books, sizeof(stBook), BOOKS);
    totalComments = readFile(comments, sizeof(stComment), COMMENTS);
}

void saveDataMenu() /// GUARDA LOS DATOS DE LOS ARCHIVOS
{
    saveFile(users, sizeof(stUser), totalUsers, USERS, compareUserId);
    saveFile(books, sizeof(stBook), totalBooks, BOOKS, compareBookId);
    saveFile(comments, sizeof(stComment), totalComments, COMMENTS, compareCommentId);
}

/* >>>>>>>>>>>>>>>>>>>DATA<<<<<<<<<<<<<<<<<<<<< */


/* >>>>>>>>>>>>>>>>>>>LOGIN/REGISTER<<<<<<<<<<<<<<<<<<<<< */

void run() /// INICIA LA APLICACION
{
    readDataMenu();

    char quit;

    do
    {
        int index = registerLoginMenu();
        quit = userMenu(index);
    }
    while(quit != 27);

    saveDataMenu();
}

int registerLoginMenu() /// MENU DE LOGIN/REGISTER
{
    char option[9];
    int index = -1;

    while(index == -1)
    {
        printf("Ingrese la accion que desea realizar: (Registrar/Ingresar)\n");
        fflush(stdin);
        getString(option, 9);

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

/* >>>>>>>>>>>>>>>>>>>LOGIN/REGISTER<<<<<<<<<<<<<<<<<<<<< */


/* >>>>>>>>>>>>>>>>>>>USERS<<<<<<<<<<<<<<<<<<<<< */

char userMenu(int index) /// MENU PRINCIPAL DE ACCIONES DE USUARIO
{
    char option;

    do
    {
        system("cls");
        printf("MENU PRINCIPAL\n\n");
        printf("  [0]  Cerrar sesion.\n");
        printf("  [1]  Perfil.\n");
        printf("  [2]  Editar informacion personal.\n");
        printf("  [3]  Ver listado de libros.\n");
        printf("  [4]  Ver libros favoritos.\n");
        printf("  [5]  Buscar libro.\n");
        printf("  [6]  Agregar un libro.\n");
        printf("  [7]  Eliminar cuenta.\n");
        if (users[index].isAdmin == 1)
        {
            printf("  [8]  Menu admin.\n");
        }
        printf("[esc]  Salir.\n");

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
                printUserExtended(users, index);
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
                if(users[index].numFavorites > 0){
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
                searchBooksMenu(index);
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
                    deleteUser(users[index].userId, users, &totalUsers);
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
                if(users[index].isAdmin)
                {
                    option = adminMenu(index);
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
    while (option != '0' && option != 27);

    return option;

}

void userInfoMenu (int index) /// MENU DE USUARIO PARA MODIFICAR INFORMACION PERSONAL
{
    char option;

    do
    {
        system("cls");
        printf("INFORMACION PERSONAL\n\n");

        printf("  [1]  Editar Email.\n");
        printf("  [2]  Editar Contraseña.\n");
        printf("  [3]  Editar Nombre de Usuario.\n");
        printf("  [4]  Editar Genero.\n");
        printf("  [5]  Editar Fecha de Nacimiento.\n");
        printf("  [6]  Editar DNI.\n");
        printf("  [7]  Editar Direccion.\n");
        printf("[esc]  Volver.\n");

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
            sleep(1);
            break;
        }
        case '2':
        {
            system("cls");
            newPassword(users, index);
            printf("La contraseña ha sido actualizada\n");
            sleep(1);
            break;
        }
        case '3':
        {
            system("cls");
            newUserName(users, index);
            printf("El nombre de usuario ha sido actualizado a %s\n", users[index].username);
            sleep(1);
            break;
        }
        case '4':
        {
            system("cls");
            newGender(users, index);
            printf("El genero ha sido actualizado a %c\n", users[index].gender);
            sleep(1);
            break;
        }
        case '5':
        {
            system("cls");
            newBirthDate(users, index);
            printf("La fecha de nacimiento ha sido actualizada a %s\n", users[index].birthDate);
            sleep(1);
            break;
        }
        case '6':
        {
            system("cls");
            newDni(users, index);
            printf("El DNI ha sido actualizado a %s\n", users[index].dni);
            sleep(1);
            break;
        }
        case '7':
        {
            system("cls");
            newAdress(users, index);
            printf("La direccion ha sido actualizada\n");
            sleep(1);
            break;
        }
        }
    }
    while(option != 27);
}

/* >>>>>>>>>>>>>>>>>>>USERS<<<<<<<<<<<<<<<<<<<<< */


/* >>>>>>>>>>>>>>>>>>>ADMIN<<<<<<<<<<<<<<<<<<<<< */

char adminMenu(int index) /// MENU EXCLUSIVO DE USUARIOS ADMIN
{
    char option;

    do
    {
        system("cls");
        printf("MENU ADMIN\n\n");
        printf("  [0]  Cerrar sesion.\n");
        printf("  [1]  Dashboard.\n");
        printf("  [2]  Buscar libro.\n");
        printf("  [3]  Buscar usuario.\n");
        printf("  [4]  Ir al menu de usuario.\n");
        printf("[esc]  Salir.\n");

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
            dashboardMenu(index);
            break;
        }
        case '2':
        {
            system("cls");
            searchBooksMenu(index);
            break;
        }
        case '3':
        {
            searchUsersMenu(index);
            break;
        }
        case '4':
        {
            system("cls");
            break;
        }
        case 27:
        {
            system("cls");
            break;
        }
        }

    }
    while (option != '0' && option != 27 && option != '4');

    return option;
}

void dashboardMenu(int index) /// MENU DE ESTADISTICAS DE LA APLICACION
{
    char option;

    do
    {
        system("cls");
        printf("DASHBOARD \n\n");
        printf("  [1]  Ver Usuarios (%d)\n", totalUsers);
        printf("  [2]  Ver Libros (%d)\n", totalBooks);
        printf("  [3]  Ver Comentarios (%d)\n", totalComments);
        printf("  [4]  Ver ultimo Usuario registrado.\n");
        printf("  [5]  Ver ultimo Libro registrado.\n");
        printf("[esc]  Salir.\n");

        fflush(stdin);
        option = getch();

        switch(option)
        {
        case '1':
        {
            paginated(index, users, &totalUsers, 5, printUser, userHandleMenu);
            system("cls");
            break;
        }
        case '2':
        {
            paginated(index, books, &totalBooks, 5, printBook, bookHandleMenu);
            break;
        }
        case '3':
        {
            paginated(index, comments, &totalComments, 5, printComment, commentHandleMenu);
            break;
        }
        case '4':
        {
            system("cls");
            userHandleMenu(index, users, &totalUsers, totalUsers - 1);
            break;
        }
        case '5':
        {
            system("cls");
            bookHandleMenu(index, books, &totalBooks, totalBooks - 1);
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

/* >>>>>>>>>>>>>>>>>>>ADMIN<<<<<<<<<<<<<<<<<<<<< */


/* >>>>>>>>>>>>>>>>>>>UTILITIES<<<<<<<<<<<<<<<<<<<<< */

void paginated(int index, void *elements, int *totalElements, int pageSize, printFunction printElement, elementMenu handleMenu) /// PAGINADO
{
    int currentPage = 1;

    while(currentPage >= 1)
    {
        system("cls");
        printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
        displayPage(elements, *totalElements, currentPage, pageSize, printElement);
        printf("~ %d ~\n", currentPage);
        currentPage = handleInput(index, elements, totalElements, currentPage, handleMenu);
    }
}

void displayPage(const void *elements, int totalElements, int page, int pageSize, printFunction printElement) /// FUNCION PARA MOSTRAR LAS PAGINAS
{
    int start = (page - 1) * pageSize;
    int end = start + pageSize;

    if (end > totalElements)
    {
        end = totalElements;
    }

    for (int i = start; i < end; i++)
    {
        printf("%d.\n\n", i - start + 1);
        printElement(elements, i);
    }
}

int handleInput(int index, void *elements, int *totalElements, int currentPage, elementMenu handleMenu) /// MANEJA LA OPCION QUE INGRESE EL USUARIO
{
    char key;

    do{

        fflush(stdin);
        key= getch();

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
            handleMenu(index, elements, totalElements, (((currentPage - 1) * 5) + (int) key - 49));
        }
        else if(key == 27)
        {
            return -1;
        }
    }while(!(key == 27 || key == 77 || key == 75 || (key >= 49 && key <= 53)));

    return currentPage;
}

void sortBooksMenu(int index, void *elements, int *totalElements) /// ORDENA EL ARREGLO DE LIBROS
{
    stBook *arrBooks = (stBook *) elements;
    char opcion ;

    do
    {
        system("cls");
        printf("Seleccione como desea ver ordenados los libros: \n\n");
        printf("  [1] Por valoración.\n");
        printf("  [2] Por categoría.\n");
        printf("  [3] Por orden alfabético.\n");
        if(users[index].isAdmin)
        {
            printf("  [4] Por ID.\n");
        }
        printf("[esc] Volver al menu.\n");

        fflush(stdin);
        opcion = getch();
        switch(opcion){
            case '1':
                qsort(arrBooks, *totalElements, sizeof(stBook), compareRating);
                paginated(index, arrBooks, totalElements, 5, printBook, bookHandleMenu);
                break;

            case '2':
                qsort(arrBooks, *totalElements, sizeof(stBook), compareCategory);
                paginated(index, arrBooks, totalElements, 5, printBook, bookHandleMenu);
                break;

            case '3':
                qsort(arrBooks, *totalElements, sizeof(stBook), compareTitle);
                paginated(index, arrBooks, totalElements, 5, printBook, bookHandleMenu);
                break;
            case '4':
                if(users[index].isAdmin)
                {
                    qsort(arrBooks, *totalElements, sizeof(stBook), compareBookId);
                    paginated(index, arrBooks, totalElements, 5, printBook, bookHandleMenu);
                }
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
    }
    while(opcion != 27);
}

void bookHandleMenu(int index, void *elements, int *totalElements, int bookIndex) /// SE MUESTRA AL ENTRAR AL DETALLE DE UN LIBRO
{
    stBook *handleBooks = (stBook *) elements;
    stComment handleComments[100];


    if(isNotEmpty(handleBooks[bookIndex].title) && !handleBooks[bookIndex].deleted)
    {
        char option;

        do{
            int idBook = handleBooks[bookIndex].bookId;
            int pos = searchIndexBookById(idBook, books, totalBooks);
            int commentsInBook = haveComments(comments,totalComments,idBook, handleComments);

            system("cls");
            if (users[index].isAdmin)
            {
                printBookAdmin(handleBooks, bookIndex);
            }
            else
            {
                printBookExtended(handleBooks, bookIndex);
            }

            printf("\n\n");
            printf("  [1]  %s favoritos.\n", isFavorite(users[index], handleBooks[bookIndex].bookId) ? "Quitar de" : "Agregar a");
            printf("  [2]  Agregar comentario.\n");
            printf("  [3]  Ver comentarios (%d)\n", commentsInBook);
            if (users[index].isAdmin){
                printf("  [4]  Modificar libro.\n");
                printf("  [5]  %s libro.\n", books[pos].deleted == 0 ? "Deshabilitar" : "Activar");
                printf("  [6]  Eliminar libro.\n");
            }
            printf("[esc]  Salir.\n");
            printf("<-  -> ");

            fflush(stdin);
            option = getch();

            switch(option)
            {
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
                    system("cls");
                    commentRegister(comments, &totalComments,users[index].userId, idBook);
                    books[pos].rating = changeRatingBook(comments, totalComments, idBook);
                    handleBooks[bookIndex] = books[pos];
                    break;
                case '3':
                    system("cls");

                    if(commentsInBook){
                            if(users[index].isAdmin)
                            {
                                paginated(index, handleComments, &commentsInBook, 5, printCommentAdmin, commentHandleMenu);
                            }else{
                                paginated(index, handleComments, &commentsInBook, 5, printComment, commentHandleMenu);
                            }
                    } else{
                        printf("El libro no tiene comentarios.\n");
                        sleep(1);
                    }
                    break;
                case '4':
                    if (users[index].isAdmin)
                    {
                        system("cls");
                        editBookMenu(idBook);
                        handleBooks[bookIndex] = books[pos];
                    }
                    break;
                case '5':
                    system("cls");
                    if (users[index].isAdmin)
                    {
                        if(books[pos].deleted){
                            activateBook(idBook, books, &totalBooks);
                        } else {
                            disableBook(idBook, books, &totalBooks);
                            for (int i = 0; i < totalUsers; i++)
                            {
                                removeFavorite(users, i, idBook);
                            }
                        }
                        printf("Se %s el libro: %s\n", books[pos].deleted == 0 ? "activo" : "deshabilito", handleBooks[bookIndex].title);
                        handleBooks[bookIndex] = books[pos];
                        sleep(1);
                    }
                    break;
                case '6':
                    if (users[index].isAdmin)
                    {
                        system("cls");
                        handleBooks[bookIndex].deleted = 1;
                        for (int i = 0; i < totalUsers; i++)
                        {
                            removeFavorite(users, i, idBook);
                        }
                        deleteCommentsBook(comments, &totalComments, idBook);
                        deleteBook(idBook, books, &totalBooks);
                        printf("El libro se elimino correctamente.\n");
                        sleep(1);
                        option = 27;
                    }
                    break;
            case -32:

                    fflush(stdin);
                    option = getch();

                    switch (option)
                    {
                    case 77:
                        if (bookIndex < totalUsers)
                        {
                            bookIndex++;
                        }
                        break;
                    case 75:
                        if (bookIndex > 0)
                        {
                            bookIndex--;
                        }
                        break;
                    }
            case 27:
                system("cls");
                break;
            }


        } while(option != 27);
    }


}

void userHandleMenu(int index, void *elements, int *totalElements, int userIndex) /// SE MUESTRA AL ENTRAR AL DETALLE DE UN USUARIO (ADMIN)
{
    stUser *handleUsers = (stUser *) elements;

    if(isNotEmpty(handleUsers[userIndex].email))
    {
        char option;

        do
        {
            int idUser = handleUsers[userIndex].userId;
            int pos = userIndexById(users, idUser, totalUsers);
            system("cls");
            printUserExtended(handleUsers, userIndex);

            printf("\n\n");
            printf("  [1]  %s admin.\n", handleUsers[userIndex].isAdmin ? "Quitar" : "Dar");
            printf("  [2]  %s usuario.\n", handleUsers[userIndex].deleted ? "Activar" : "Desactivar");
            printf("  [3]  Eliminar usuario (permanente).\n");
            printf("[esc]  Salir.\n\n");
            printf("<-  -> ");

            fflush(stdin);
            option = getch();

            switch(option)
            {
                case '1':

                    if(handleUsers[userIndex].isAdmin && index != userIndex)
                    {
                        handleUsers[userIndex].isAdmin = 0;
                    }
                    else
                    {
                        handleUsers[userIndex].isAdmin = 1;
                    }
                    printf("Se %s admin al usuario %s", handleUsers[userIndex].isAdmin ? "dió" : "quitó", handleUsers[userIndex].username);
                    sleep(1);
                    break;
                case '2':

                    if(handleUsers[userIndex].deleted)
                    {
                        users[pos].deleted = 0;
                        handleUsers[userIndex].deleted = 0;
                    }
                    else
                    {
                        users[pos].deleted = 1;
                        handleUsers[userIndex].deleted = 1;
                    }
                    printf("Se %s al usuario %s", handleUsers[userIndex].deleted ? "desactivó" : "activó", handleUsers[userIndex].username);
                    sleep(1);
                    break;
                case '3':
                    deleteUser(idUser, users, &totalUsers);
                    printf("Se elimino al usuario.");
                    handleUsers[userIndex].deleted = 1;
                    sleep(1);
                    option = 27;
                    break;
                case -32:

                    fflush(stdin);
                    option = getch();

                    switch (option)
                    {
                    case 77:
                        if (userIndex < totalUsers)
                        {
                            userIndex++;
                        }
                        break;
                    case 75:
                        if (userIndex > 0)
                        {
                            userIndex--;
                        }
                        break;
                    }

                case 27:

                    system("cls");
                    break;
            }


        }
        while(option != 27);
    }

}

void commentHandleMenu(int index, void *elements, int *totalElements, int commentIndex) /// SE MUESTRA AL ENTRAR AL DETALLE DE UN COMENTARIO
{
    stComment *handleComments = (stComment *) elements;

    if(isNotEmpty(handleComments[commentIndex].commentTitle))
    {
        char option;

        do
        {
            int idComment = handleComments[commentIndex].commentId;
            int pos = searchIndexBookById(handleComments[commentIndex].bookId, books, totalBooks);

            system("cls");
            if (users[index].isAdmin)
            {
                printCommentAdmin(handleComments, commentIndex);
            }
            else
            {
                printComment(handleComments, commentIndex);
            }


            printf("\n\n");
            if (users[index].isAdmin){
                printf("  [1]  %s comentario.\n", handleComments[commentIndex].deleted ? "Activar" : "Desactivar");
            } else if (users[index].userId == handleComments[commentIndex].userId && !users[index].isAdmin){
                printf("  [1]  Modificar comentario.\n");
            }
            if (users[index].isAdmin || users[index].userId == handleComments[commentIndex].userId)
            {
                printf("  [2]  Eliminar comentario.\n");
            }
            printf("[esc]  Salir.\n\n");
            printf("<-  -> ");

            fflush(stdin);
            option = getch();

            switch(option)
            {
                case '1':

                    if(users[index].isAdmin){
                        if(handleComments[commentIndex].deleted)
                        {
                            handleComments[commentIndex].deleted = 0;
                        }
                        else
                        {
                            handleComments[commentIndex].deleted = 1;
                        }
                        printf("Se %s el comentario", handleComments[commentIndex].deleted ? "desactivó" : "activó");
                    } else if(users[index].userId == handleComments[commentIndex].userId){
                        editCommentMenu(idComment);
                        books[pos].rating = changeRatingBook(comments, totalComments, handleComments[commentIndex].bookId);
                    }
                    sleep(1);
                    break;
                case '2':
                    if(users[index].isAdmin || users[index].userId == handleComments[commentIndex].userId)
                    {
                        handleComments[commentIndex].deleted = 1;
                        deleteComment(idComment, comments, &totalComments);
                        books[pos].rating = changeRatingBook(comments, totalComments, handleComments[commentIndex].bookId);
                        printf("Se elimino el comentario.");
                        sleep(1);
                        option = 27;
                    }
                    break;
                case -32:

                    fflush(stdin);
                    option = getch();

                    switch (option)
                    {
                    case 77:
                        if (commentIndex < totalUsers-1)
                        {
                            commentIndex++;
                        }
                        break;
                    case 75:
                        if (commentIndex > 0)
                        {
                            commentIndex--;
                        }
                        break;
                    }

                case 27:

                    system("cls");
                    break;
            }


        }
        while(option != 27);
    }
}

void searchUsersMenu(int index) /// MENU DE BUSQUEDA DE USUARIOS
{
    char opcion ;

    do
    {
        system("cls");
        printf("Seleccione como desea buscar usuarios: \n");
        printf("  [1] Por nombre de usuario.\n");
        printf("  [2] Por ID.\n");
        printf("[esc] Volver al menu.\n");

        fflush(stdin);
        opcion = getch();
        switch(opcion)
        {
        case 49:
            searchUsersByUsername(index, users, totalUsers);
            break;
        case 50:
            searchUsersById(index, users, totalUsers);
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
    }
    while(opcion != 49 && opcion != 50 && opcion != 27);
}

void searchBooksMenu(int index) /// MENU DE BUSQUEDA DE LIBROS
{
    char opcion ;

    do
    {
        printf("Seleccione como desea buscar libros: \n");
        printf("  [1] Por titulo.\n");
        printf("  [2] Por autor.\n");
        printf("  [3] Por categoria.\n");
        printf("[esc] Volver al menu.\n");

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
            sleep(1);
            system("cls");
            break;
        }
    }
    while(opcion != 49 && opcion != 50 && opcion != 51 && opcion != 27);
}

void editBookMenu(int idBook) /// PERMITE EDITAR UN LIBRO
{
    char option;
    int indexBook = searchIndexBookById(idBook, books, totalBooks);
    do
    {
        system("cls");
        printf("Dato que quiere editar: \n\n");

        printf("  [1]  Editar titulo.\n");
        printf("  [2]  Editar editorial.\n");
        printf("  [3]  Editar autor.\n");
        printf("  [4]  Editar categoria.\n");
        printf("[esc]  Volver.\n");

        fflush(stdin);
        option = getch();

        switch(option)
        {
        case 27:
            system("cls");
            break;
        case '1':
            system("cls");
            printf("El titulo actual es: %s\n", books[indexBook].title);
            newTitle(books, indexBook);
            printf("El titulo ha sido actualizado a %s\n", books[indexBook].title);
            system("pause");
            break;
        case '2':
            system("cls");
            printf("La editorial actual es: %s\n", books[indexBook].publisher);
            newPublisher(books, indexBook);
            printf("La editorial ha sido actualizado a %s\n", books[indexBook].publisher);
            system("pause");
            break;
        case '3':
            system("cls");
            printf("El autor actual es: %s\n", books[indexBook].author);
            newAuthor(books, indexBook);
            printf("El autor ha sido actualizado a %s\n", books[indexBook].author);
            system("pause");
            break;
        case '4':
            system("cls");
            printf("La categoria actual es: %s\n", books[indexBook].category);
            newCategory(books, indexBook);
            printf("El categoria ha sido actualizado a %s\n", books[indexBook].category);
            system("pause");
            break;
        }
    }
    while(option != 27);
}

void editCommentMenu(int idComment) /// PERMITE EDITAR UN COMENTARIO
{

    char option;
    int indexComment = commentIndexById(comments, idComment, totalComments);
    do
    {
        system("cls");
        printf("Dato que quiere editar: \n\n");

        printf("  [1]  Editar titulo.\n");
        printf("  [2]  Editar descripcion.\n");
        printf("  [3]  Editar valoracion.\n");
        printf("[esc]  Volver.\n");

        fflush(stdin);
        option = getch();

        switch(option)
        {
        case 27:
            system("cls");
            break;
        case '1':
            system("cls");
            printf("El titulo actual es: %s\n", comments[indexComment].commentTitle);
            newCommentTitle(comments, indexComment);
            printf("El titulo ha sido actualizado a %s\n", comments[indexComment].commentTitle);
            system("pause");
            break;
        case '2':
            system("cls");
            printf("La descripcion actual es: %s\n", comments[indexComment].description);
            newDescription(comments, indexComment);
            printf("La descripcion ha sido actualizado a %s\n", comments[indexComment].description);
            system("pause");
            break;
        case '3':
            system("cls");
            printf("Ingrese una nueva valoracion:\n");
            newRating(comments, indexComment);
            printf("La valoracion ha sido actualizada a: %d\n", comments[indexComment].rating);
            system("pause");
            break;
        }
    }
    while(option != 27);
}


/* >>>>>>>>>>>>>>>>>>>UTILITIES<<<<<<<<<<<<<<<<<<<<< */

