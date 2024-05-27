#include "user-data.h"


void newEmail (stUser *users, int index) //comprueba el mail y lo carga
{
    printf("Ingrese un mail valido: ");
    fflush(stdin);
    gets(users[index].email);
    system("cls");

    if (existingEmail(users[index].email, users, index))  // mientras el mail ya este registrado se repite el bucle recursivo
    {
        printf("El mail ingresado ya esta registrado. ");

        newEmail(users, index);
    }
    else if (!validEmail(users[index].email)) // mientras el mail no sea valido se repite el bucle recursivo
    {
        printf("El mail ingresado no es valido. ");

        newEmail(users, index);
    }
}

void getPass(char *pass) // permite escribir una contraseņa sin mostrar el contenido
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

void newPassword(stUser *users, int index) // asigna una contraseņa a un usuario nuevo
{
    char pass[20];

    printf("Cree una nueva contraseņa: ");
    getPass(pass);
    system("cls");
    if (validPassword(pass)) // mientras la contraseņa no sea valida se repite el bucle recursivo
    {
        printf("Repita su contraseņa: ");
        getPass(users[index].password);
        system("cls");

        if (!matchPassword(users[index].password, pass)) // mientras la contraseņas no coincidan se repite el bucle recursivo
        {
            printf("Las contraseņas no coinciden.\n\n");
            newPassword(users, index);
        }
    }
    else
    {
        newPassword(users, index);
    }


}

void newUserName (stUser *users, int index) // carga un nuevo nombre de usuario
{
    printf("Ingrese su nuevo nombre de usuario: ");
    fflush(stdin);
    gets(users[index].username);
    system("cls");

    if (!validUserName(users[index].username, users, index))
    {
        newUserName(users, index);
    }
}

void newAdress (stUser *users, int index)
{
    printf("Domicilio: \n");
    printf("\nCalle: ");
    fflush(stdin);
    gets(users[index].address.street);
    printf("\nAltura: ");
    fflush(stdin);
    gets(users[index].address.number);
    printf("\nCodigo Postal: ");
    fflush(stdin);
    gets(users[index].address.zipCode);
    printf("\nCiudad: ");
    fflush(stdin);
    gets(users[index].address.city);
    printf("\nProvincia: ");
    fflush(stdin);
    gets(users[index].address.province);
    printf("\nPais: ");
    fflush(stdin);
    gets(users[index].address.country);
    system("cls");
}

void newGender(stUser *users, int index)
{
    printf("Seleccione el genero con el que se identifica: (M / F)\n");
    fflush(stdin);
    users[index].gender = toupper(getchar());

    if (users[index].gender != 'M' && users[index].gender != 'F')
    {
        system("cls");
        printf("El valor ingresado es incorrecto. \n");
        newGender(users, index);
    }
    system("cls");
}

void newBirthDate(stUser *users, int index)
{
    int day, month, year;

    printf("Ingrese su fecha de nacimiento: \n");

    printf("\nAņo: ");
    scanf("%d", &year);

    printf("\nMes: ");
    scanf("%d", &month);

    printf("\nDia: ");
    scanf("%d", &day);

    system("cls");

    if(!validDate(year, month, day))
    {
        newBirthDate(users, index);
    }
    else
    {
        sprintf(users[index].birthDate, "%d/%02d/%02d", year, month, day);
    }

}

void newDni(stUser *users, int index)
{
    printf("Ingrese su numero de DNI: ");
    fflush(stdin);
    gets(users[index].dni);

    if (!validDni(users[index].dni))
    {
        system("cls");
        printf("El DNI ingresado no es valido. ");
        newDni(users, index);
    }
    system("cls");
}

//void newFavoriteBook(stUser users, int index)
//{
//    printf("Ingrese el ID de un libro para marcarlo como favorito: ");
//
//}



