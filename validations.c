#include "validations.h"



int isNotEmpty(char field[]) // valida que un string no este vacio
{
    return strlen(field) > 0;
}

int yesNo ()
{
    char option;

    do
    {
        fflush(stdin);
        option = tolower(getch());
    }while(option != 'y' && option != 'n');

    if(option == 'y')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int getNumber() // permite escribir unicamente numeros
{
    char num[20];
    int i = 0;

    while (num[i] != 13)
    {
        do
        {
            fflush(stdin);
            num[i] = getch();
        }while(!isdigit(num[i]) && num[i] != 13 && num[i] != 8);

        if (num[i] != 13 && num[i] != 8) // si la tecla pulsada no es intro ni backspace imprime el numero
        {
            printf("%c", num[i]);
            i++;
        }
        else if (num[i] == 8 && i > 0) // si se pulsa backspace mueve el cursor atras, imprime un espacio y mueve atras de nuevo
        {
            printf("\b \b");
            i--;
        }
    }
    num[i] = 0;
    printf("\n");

    return atoi(num);
}

void getString(char* str, int maxBufferSize) // permite escribir un string evaluando cada caracter
{
    if(strlen(str) <= maxBufferSize)
    {
        gets(str);
    }
}

void newField(char field[], char prompt[], int maxBufferSize){

    do{
        printf("%s", prompt);
        fflush(stdin);
        getString(field, maxBufferSize);
        system("cls");
        if(!isNotEmpty(field)){
            printf("El campo no puede estar vacio.\n\n");
        }
    } while(!isNotEmpty(field));
}



/* >>>>>>>>>>>>>>>>>>>BOOKS<<<<<<<<<<<<<<<<<<<<< */

int existingBook(char title[], stBook books[], int index) // valida que un libro exista
{
    int i = 0;
    int flag = 0;

    while (i < index && flag == 0)
    {
        if (strcmpi(books[i].title, title) == 0)
        {
            flag = 1;
        }
        i++;
    }

    return flag;
}

int isFavorite(stUser user, int bookId)
{
    int i = 0;

    while (i < user.numFavorites)
    {
        if(user.favoriteBooks[i] == bookId)
        {
            return 1;
        }
        i++;
    }

    return 0;
}

/* >>>>>>>>>>>>>>>>>>>BOOKS<<<<<<<<<<<<<<<<<<<<< */




/* >>>>>>>>>>>>>>>>>>>USERS<<<<<<<<<<<<<<<<<<<<< */


int validEmail(char *email) // valida que un mail sea valido
{
    int i = 0, a = 0;

    while(email[i] != 0 && email[i] != ' ')
    {
        if (email[i] == '@' && i > 0)
        {
            a++;
        }
        if (email[i] == '.' && a == 1 && email[i-1] != '@')
        {
            i++;
            if (email[i] == 'c' && email[i+1] == 'o' && email[i+2] == 'm')
            {
                return 1;
            }
        }
        i++;
    }

    return 0;
}

int existingEmail(char *mail, stUser *users, int index) // valida que un email esta registrado y devuelve la posicion en el arreglo
{
    int i = 0;

    while (i < index)
    {
        if (strcmpi(users[i].email, mail) == 0)
        {
            return i;
        }
        i++;
    }

    return 0;
}

int validPassword(char *pass) // comprueba que la contrase�a sea valida
{
    int size = strlen(pass);
    int upper = 0, lower = 0, num = 0, special = 0;

    if (size < 8 || size > 20)
    {
        system("cls");
        printf("La contrase�a debe tener entre 8 y 20 caracteres.\n\n");
        return 0;
    }

    for (int i = 0; i < size; i++) // valida que se cumplan los requisitos
    {
        if (isupper(pass[i]))
        {
            upper = 1;
        }
        else if (islower(pass[i]))
        {
            lower = 1;
        }
        else if (isdigit(pass[i]))
        {
            num = 1;
        }
        else if (strchr("!@#$%^&*()-_=+[]{};:,.<>/?\\|`~", pass[i]))
        {
            special = 1;
        }
        else if (isspace(pass[i]))
        {
            return 0;
        }
    }

    if (upper && lower && num && special)
    {
       return 1;
    }
    else
    {
        system("cls");
        printf("La contrase�a debe incluir al menos una: Mayuscula, Minuscula, Numero, Caracter especial.\n\n");

        return 0;
    }

}

int matchPassword(char *pass1, char *pass2) // evalua que las contrase�as coincidan
{
    if (strcmp(pass1, pass2) != 0)
    {
        return 0;
    }

    return 1;
}

int validUserName(char *uName, stUser *users, int index) // valida que el nombre de usuario sea valido y no se repita
{
    int size = strlen(uName);
    int i = 0;

    if (size < 4 || size > 20)
    {
        system("cls");
        printf("El nombre de usuario debe tener entre 4 y 20 caracteres.\n\n");
        return 0;
    }

    while (i < index)
    {
        if (strcmpi(users[i].username, uName) == 0)
        {
            system("cls");
            printf("El nombre de usuario ya existe.\n\n");
            return 0;
        }
        i++;
    }

    return 1;
}

int validGender(char gender)
{
    if (gender != 'M' && gender != 'F')
    {
        printf("El valor ingresado es incorrecto. \n");
        system("pause");
        return 0;
    }
    return 1;
}

int validDate(int year, int month, int day)
{
    if (year < 1900 || year > 2023)
    {
        printf("El a�o seleccionado no es valido. ");
    }
    else if (month < 1 || month > 12)
    {
        printf("El mes seleccionado no es valido. ");
    }
    else if (day > 31 || day < 1 || (month == 2 && day > 28) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30))
    {
        printf("El dia seleccionado no es valido. ");
    }
    else
    {
        return 1;
    }

    return 0;

}

int validDni(char *dni)
{
    int i = 0, lon = strlen(dni);

    if (lon < 9 && lon > 6)
    {
        while(i < lon)
        {
            if(!isdigit(dni[i]))
            {
                return 0;
            }
            i++;
        }
        return 1;
    }
    else
    {
        return 0;
    }

}

int matchId (stUser *users, int id, int totalUsers) // valida que exista un id y devuelve la posicion
{
    int i = 0;

    while (i < totalUsers)
    {
        if (users[i].userId == id)
        {
            return i;
        }
        i++;
    }

    return -1;
}

int compareUserId(const void *a, const void *b)
{
    stUser *userA = (stUser *) a;
    stUser *userB = (stUser *) b;
    return (userA->userId - userB->userId);
}

/* >>>>>>>>>>>>>>>>>>>USERS<<<<<<<<<<<<<<<<<<<<< */


/* >>>>>>>>>>>>>>>>>>>COMMENTS<<<<<<<<<<<<<<<<<<<<< */

int compareCommentId(const void *a, const void *b)
{
    stComment *commentA = (stComment *) a;
    stComment *commentB = (stComment *) b;
    return (commentA->commentId - commentB->commentId);
}

/* >>>>>>>>>>>>>>>>>>>COMMENTS<<<<<<<<<<<<<<<<<<<<< */

