#include "coment-data.h"


void newCommentField(char field[], char prompt[])
{

    do
    {
        printf("%s", prompt);
        fflush(stdin);
        gets(field);
        system("cls");
        if(!isNotEmpty(field))
        {
            printf("El campo no puede estar vacio.\n\n");
        }
    }
    while(!isNotEmpty(field));
}

void newCommentTitle(stComment comments[], int index)
{
    newCommentField(comments[index].commentTitle, "Ingrese el título del comentario: ");
}

void newDescription(stComment comments[], int index)
{
    newCommentField(comments[index].description, "Ingrese la descripción del comentario: ");
}

void newRating(stComment comments[], int index)
{
    int star=0;
    do
    {
        printf("Ingrese su valoración del 1 al 5: ");
        scanf("%d",&star);
        if(star>=1 && star<=5)
        {
            comments[index].rating = star;
        }
        else
        {
            printf("Valor invalido.\n");
        }
        system("cls");
    }
    while (star<1 || star>5);
}

void newDate(stComment comments[], int index)
{
    time_t now;
    struct tm *local;
    now = time(NULL);
    local = localtime(&now);

    strftime(comments[index].commentDate,sizeof(comments[index].commentDate),"%Y/%m/%d %H:%M:%S",local);
}


