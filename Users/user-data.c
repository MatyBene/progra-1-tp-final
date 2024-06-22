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

int getFirstFreeId (stUser *users, int totalUsers)
{
    int i = 0;

    while (i < totalUsers && i == users[i].userId-1)
    {
        i++;
    }

    return i+1;
}

void newPassword(stUser *users, int index) // asigna una contraseña a un usuario nuevo
{
    char pass[20];

    printf("Cree una nueva contraseña: ");
    getPass(pass);
    system("cls");
    if (validPassword(pass)) // mientras la contraseña no sea valida se repite el bucle recursivo
    {
        printf("Repita su contraseña: ");
        getPass(users[index].password);
        system("cls");

        if (!matchPassword(users[index].password, pass)) // mientras la contraseñas no coincidan se repite el bucle recursivo
        {
            printf("Las contraseñas no coinciden.\n\n");
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

void newAdress (stUser *users, int index) // llama a las funciones de carga de domicilio
{
    newStreet(users, index);
    newZipCode(users, index);
    newCity(users, index);
    newProvince(users, index);
    newCountry(users, index);
    system("cls");
}

void newStreet(stUser *users, int index) // carga una nueva calle
{
    printf("Domicilio: \n");
    printf("\nCalle: ");
    fflush(stdin);
    gets(users[index].address.street);
    printf("\nAltura: ");
    itoa(getNumber(), users[index].address.number, 10);
}

void newZipCode(stUser *users, int index) // carga un nuevo codigo postal
{
    printf("\nCodigo Postal: ");
    fflush(stdin);
    gets(users[index].address.zipCode);
}

void newCity(stUser *users, int index)  // carga una nueva ciudad
{
    printf("\nCiudad: ");
    fflush(stdin);
    gets(users[index].address.city);
}

void newProvince(stUser *users, int index)  // carga una nueva provincia
{
    printf("\nProvincia: ");
    fflush(stdin);
    gets(users[index].address.province);
}

void newCountry(stUser *users, int index)   // carga un nuevo pais
{
    printf("\nPais: ");
    fflush(stdin);
    gets(users[index].address.country);
}

void newGender(stUser *users, int index) // carga un nuevo genero
{
    printf("Seleccione el genero con el que se identifica: (M / F)\n");
    fflush(stdin);
    users[index].gender = toupper(getch());

    if (!validGender(users[index].gender))
    {
        system("cls");
        newGender(users, index);
    }

    system("cls");
}

void newBirthDate(stUser *users, int index) // carga una nueva fecha de nacimiento
{
    int day, month, year;

    printf("Ingrese su fecha de nacimiento: \n");

    printf("\nAño: ");
    year = getNumber();

    printf("\nMes: ");
    month = getNumber();

    printf("\nDia: ");
    day = getNumber();

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

void newDni(stUser *users, int index) // carga un nuevo dni
{
    printf("Ingrese su numero de DNI: ");
    itoa(getNumber(), users[index].dni, 10);

    if (!validDni(users[index].dni))
    {
        system("cls");
        printf("El DNI ingresado no es valido. ");
        newDni(users, index);
    }
    system("cls");
}




