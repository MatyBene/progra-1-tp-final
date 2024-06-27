#include "user-data.h"



void newEmail (stUser *users, int index) /// COMPRUEBA QUE EL MAIL SEA CORRECTO Y LO CARGA
{
    printf("Ingrese un mail valido: ");
    fflush(stdin);
    getString(users[index].email, 100);
    system("cls");

    if (existingEmail(users[index].email, users, index))  /// EVALUA QUE EL MAIL NO ESTE REGISTRADO
    {
        printf("El mail ingresado ya esta registrado. ");

        newEmail(users, index);
    }
    else if (!validEmail(users[index].email)) /// EVALUA QUE EL MAIL SEA VALIDO
    {
        printf("El mail ingresado no es valido. ");

        newEmail(users, index);
    }
}

void getPass(char *pass) /// PERMITE ESCRIBIR SIN MOSTRAR EL CONTENIDO EN CONSOLA
{
    int i = 0;

    while (pass[i] != 13)
    {
        fflush(stdin);
        pass[i] = getch();

        if (pass[i] != 13 && pass[i] != 8 && i < 20) /// si la tecla pulsada no es intro ni backspace imprime * en lugar del char
        {
            printf("*");
            i++;
        }
        else if (pass[i] == 8 && i > 0) /// si se pulsa backspace mueve el cursor atras, imprime un espacio y mueve atras de nuevo
        {
            printf("\b \b");
            i--;
        }
    }
    pass[i] = 0;
}

int getFirstFreeIdUser (stUser *users, int totalUsers) /// ENCUENTRA LA PRIMER ID DISPONIBLE DE USUARIOS Y LA DEVUELVE
{
    int i = 0;

    while (i < totalUsers && i == users[i].userId-1)
    {
        i++;
    }

    return i+1;
}

void newPassword(stUser *users, int index) /// ASIGNA UNA NUEVA CONTRASEÑA
{
    char pass[20];

    printf("Cree una nueva contraseña: ");
    getPass(pass);
    system("cls");
    if (validPassword(pass)) /// EVALUA QUE LA CONTRASEÑA SEA VALIDA
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

void newUserName (stUser *users, int index) /// ASIGNA UN NUEVO NOMBRE DE USUARIO
{
    printf("Ingrese su nuevo nombre de usuario: ");
    fflush(stdin);
    getString(users[index].username, 20);
    system("cls");

    if (!validUserName(users[index].username, users, index))
    {
        newUserName(users, index);
    }
}

void newAdress (stUser *users, int index) /// LLAMA A LAS FUNCIONES DE CARGA DE DOMICILIO
{
    newStreet(users, index);
    newZipCode(users, index);
    newCity(users, index);
    newProvince(users, index);
    newCountry(users, index);
    system("cls");
}

void newStreet(stUser *users, int index) /// ASIGNA UNA NUEVA CALLE
{
    printf("Domicilio: \n");
    printf("\nCalle: ");
    fflush(stdin);
    getString(users[index].address.street, 50);
    printf("\nAltura: ");
    itoa(getNumber(), users[index].address.number, 10);
}

void newZipCode(stUser *users, int index) /// ASIGNA UN NUEVO CODIGO POSTAL
{
    printf("\nCodigo Postal: ");
    fflush(stdin);
    getString(users[index].address.zipCode, 50);
}

void newCity(stUser *users, int index)  /// ASIGNA UNA NUEVA CIUDAD
{
    printf("\nCiudad: ");
    fflush(stdin);
    getString(users[index].address.city, 50);
}

void newProvince(stUser *users, int index)  /// ASIGNA UNA NUEVA PROVINCIA
{
    printf("\nProvincia: ");
    fflush(stdin);
    getString(users[index].address.province, 50);
}

void newCountry(stUser *users, int index)   /// ASIGNA UN NUEVO PAIS
{
    printf("\nPais: ");
    fflush(stdin);
    getString(users[index].address.country, 50);
}

void newGender(stUser *users, int index) /// ASIGNA UN NUEVO GENERO
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

void newBirthDate(stUser *users, int index) /// ASIGNA UNA NUEVA FECHA DE NACIMIENTO
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

void newDni(stUser *users, int index) /// ASIGNA UN NUEVO DNI
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

int compareUserId(const void *a, const void *b) /// FUNCION DE COMPARACION USADA EN QSORT
{
    stUser *userA = (stUser *) a;
    stUser *userB = (stUser *) b;
    return (userA->userId - userB->userId);
}

int userIndexById (stUser *users, int id, int totalUsers) /// SI EXISTE UNA ID DE USUARIO DEVUELVE LA POSICION SINO -1
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



