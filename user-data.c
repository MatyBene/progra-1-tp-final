#include "user-data.h"

void newEmail (stUser *users, int index) //comprueba que el mail no este registrado y que sea valido y lo carga
{
    printf("Ingrese un mail valido: ");

    fflush(stdin);
    gets(users[index].email);
    system("cls");


    if (existingEmail(users[index].email, users))  // mientras el mail ya este registrado se repite el bucle recursivo
    {
        printf("El mail ingresado ya esta registrado, por favor intente nuevamente. ");

        newEmail(users, index);
    }
    else if (!validEmail(users[index].email)) // mientras el mail no sea valido se repite el bucle recursivo
    {
        printf("El mail ingresado no es valido, por favor intente nuevamente. ");

        newEmail(users, index);
    }

}

int existingEmail(char *mail, stUser *users) // busca en el arreglo users.email si el mail ya existe
{
    ///int totalUsers = countUsers(users);
    int totalUsers = 3;

    int i = 0;

    while (i < totalUsers)
    {
        if (strcmpi(users[i].email, mail) == 0)
        {
            return 1;
        }
        i++;
    }

    return 0;
}

int validEmail(char *email) // comprueba que un mail sea valido
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

void getPass(char *pass) // permite escribir una contraseña sin mostrar el contenido
{
    int i = 0;

    while (pass[i] != 13)
    {
        fflush(stdin);
        pass[i] = getch();

        if (pass[i] != 13 && pass[i] != 8 && i < 20) // si la tecla pulsada no es intro ni backspace imprime * en lugar del char
        {
            printf("*");
            i++;
        }
        else if (pass[i] == 8 && i > 0) // si se pulsa backspace mueve el cursor atras, imprime un espacio y mueve atras de nuevo
        {
            printf("\b \b");
            i--;
        }
    }
    pass[i] = 0;
}

int validPassword(char *pass) // comprueba que la contraseña sea valida
{
    int size = strlen(pass);
    int upper = 0, lower = 0, num = 0, special = 0;

    if (size < 8 || size > 20)
    {
        system("cls");
        printf("La contraseña debe tener entre 8 y 20 caracteres.\n\n");
        return 0;
    }

    for (int i = 0; i < size; i++) // evaluacion de requisitos
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
        printf("La debe incluir al menos una: Mayuscula, Minuscula, Numero, Caracter especial.\n\n");

        return 0;
    }

}

int matchPassword(char *pass1, char *pass2) // evalua que las contraseñas coincidan
{
    if (strcmp(pass1, pass2) != 0)
    {
        printf("Las contraseñas no coinciden.\n\n");

        return 0;
    }

    return 1;
}
