#include "menu.h"

char userMenu(stUser *users, int index, int *totalUsers, stBook *books, int *totalBooks, stComment *comments, int *totalComments)
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
        printf("  4)  Buscar libro.\n");
        printf("  5)  Agregar un libro.\n");
        printf("  6)  Eliminar cuenta.\n");
        if (users[index].isAdmin == 1)
        {
            printf("  7)  Menu admin\n");
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
            printUser(users[index]);
            system("pause");
            break;
        }
        case '2':
        {
            userInfoMenu(users, index);
            break;
        }
        case '3':
        {
            system("cls");
            sortBooks(books, *totalBooks);
            break;
        }
        case '4':
        {
            system("cls");
            searchBooks(books, *totalBooks);
            break;
        }
        case '5':
        {
            system("cls");
            bookRegister(books, totalBooks);
            break;
        }
        case '6':
        {
            printf("Deseas eliminar tu cuenta %s? (y/n)\n", users[index].username);
            if(yesNo())
            {
                deleteUser(users, index, totalUsers);
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
        case '7':
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
    while (option != '0' && option != 27 && option != '7');

    return option;

}

void userInfoMenu (stUser *users, int index)
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

char adminMenu(stUser *users, int index, int *totalUsers, stBook *books, int *totalBooks, stComment *comments, int *totalComments)
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
            system("cls");
            dashboardMenu(users, totalUsers, books, totalBooks, comments, totalComments);
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
            option = userMenu(users, index, totalUsers, books, totalBooks, comments, totalComments);
            break;
        }

/// ESTAN COMENTADAS PARA FACILITAR RECORDAR QUE FUNCION HACIA QUE (POR LAS DUDAS JAJA)
//            case '1':
//            {
//                system("cls");
//                printAllUsers(users, *totalUsers);
//                system("pause");
//                break;
//            }
//            case '2':
//            {
//                system("cls");
//                actionUserMenu(users, totalUsers, "dar admin", makeAdmin);
//                break;
//            }
//            case '3':
//            {
//                system("cls");
//                actionUserMenu(users, totalUsers, "eliminar", deleteUser);
//                break;
//            }
//            case '4':
//            {
//                system("cls");
//                actionUserMenu(users, totalUsers, "desactivar", disableUser);
//                break;
//            }
//            case '5':
//            {
//                system("cls");
//                actionUserMenu(users, totalUsers, "activar", activateUser);
//                break;
//            }
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

void dashboardMenu(stUser *users, int *totalUsers, stBook *books, int *totalBooks, stComment *comments, int *totalComments)
{
    char option;

    do
    {
        system("cls");
        printf("DASHBOARD \n\n");
        printf("  1)  Ver Usuarios (%d)\n", *totalUsers);
        printf("  2)  Ver Libros (%d)\n", *totalBooks);
        printf("  3)  Ver Comentarios (%d)\n", *totalComments);
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

int registerLoginMenu(stUser *users, int *totalUsers)
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
            userRegister(users, totalUsers);
            index = userLogin(users, *totalUsers);
        }
        else if (strcmpi(option,"ingresar") == 0)
        {
            system("cls");
            index = userLogin(users, *totalUsers);
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

void actionUserMenu(stUser *users, int *totalUsers, char *prompt, void (*action)(stUser *, int, int *))
{
    int id, index;

    printf("Seleccione el ID del usuario a %s: \n", prompt);
    scanf("%d", &id);
    index = matchId(users, id, *totalUsers);
    if(index != -1)
    {
        printf("Desea %s al usuario %s? (y/n)\n", prompt, users[index].username);

        if (yesNo() && !users[index].isAdmin)
        {
            action(users, index, totalUsers);
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

void displayPage(const void elementsArray[], size_t elementSize, int totalElements, int page, int pageSize, printFunction printElement)
{
    const void *element = NULL;
    int start = page * pageSize;
    int end = start + pageSize;

    if (end > totalElements)
    {
        end = totalElements;
    }

    for (int i = start; i < end; i++)
    {
        printf(" %d.", i - start + 1);
        element = (const char*)elementsArray + (elementSize * i);
        printElement(element);
    }
}

int handleUserInput(const void elementsArray[], int totalElements, int currentPage, elementMenu handleMenu)
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
            if ((currentPage + 1) * 5 < totalElements)
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
        /// IR A MENU BOOK
        handleMenu(elementsArray, (currentPage * 5) + (int) key - 49))
//        system("cls");
//        printBookExtended(books, (currentPage * 5) + (int) key - 49);
//        system("pause");
    }
    else if(key == 27)
    {
        return -1;
    }
    else
    {
        handleUserInput(currentPage, books, totalBooks);
    }

    return currentPage;
}

void paginated(stBook books[], int totalBooks)
{
    int currentPage = 1;

    while(currentPage >= 1)
    {
        system("cls");
        displayPage(books, totalBooks, currentPage, 5);
        printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
        printf("~%d~\n", currentPage);
        printf("Ingrese el numero del libro que desea ver en detalle: ");
        currentPage = handleUserInput(currentPage, books, totalBooks);
    }
}

/* >>>>>>>>>>>>>>>>>>>UTILITIES<<<<<<<<<<<<<<<<<<<<< */

//void displayPage(stBook books[], int totalBooks, int page, int pageSize) {
//    int j = 0;
//    int start = page * pageSize;
//    int end = start + pageSize;
//
//    if (end > totalBooks) {
//        end = totalBooks;
//    }
//
//    for (int i = start; i < end; i++) {
//        printf(" %d.", j + 1);
//        printBook(books, i);
//        j++;
//    }
//}
//
//int handleUserInput(int currentPage, stBook books[], int totalBooks) {
//    fflush(stdin);
//    char key = getch();
//
//    if(key == -32){
//        fflush(stdin);
//        key = getch();
//
//        switch (key) {
//            case 77:
//                if ((currentPage + 1) * 5 < totalBooks) {
//                    currentPage++;
//                }
//                break;
//            case 75:
//                if (currentPage > 1) {
//                    currentPage--;
//                }
//                break;
//        }
//    }else if(key >= 49 && key <= 53){
//            system("cls");
//            printBookExtended(books, (currentPage * 5) + (int) key - 49); //ir a menuBook
//            system("pause");
//    }else if(key == 27){
//        return -1;
//    } else {
//        handleUserInput(currentPage, books, totalBooks);
//    }
//
//    return currentPage;
//}
//
//void paginated(stBook books[], int totalBooks){
//    int currentPage = 1;
//
//    while(currentPage >= 1){
//        system("cls");
//        displayPage(books, totalBooks, currentPage, 5);
//        printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
//        printf("~%d~\n", currentPage);
//        printf("Ingrese el numero del libro que desea ver en detalle: ");
//        currentPage = handleUserInput(currentPage, books, totalBooks);
//    }
//}



/* >>>>>>>>>>>>>>>>>>>UTILITIES<<<<<<<<<<<<<<<<<<<<< */
