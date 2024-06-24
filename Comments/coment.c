#include "coment.h"
#include "coment-data.h"
#include "../menu.h"

void commentRegister(stComment comments[], int *totalComments, int idUser, int idBook)
{
    comments[*totalComments].commentId = *totalComments + 1;
    comments[*totalComments].userId = idUser;
    comments[*totalComments].bookId = idBook;
    newCommentTitle(comments, *totalComments);
    newDescription(comments, *totalComments);
    newRating(comments, *totalComments);
    newDate(comments, *totalComments);
    comments[*totalComments].deleted = 0;

    (*totalComments)++;
}

void printComment(const void *elements, int index)
{
    stComment *comments = (stComment*) elements;

    printf("Titulo: ............. %s\n\n", comments[index].commentTitle);
    printf("Descripción: ........ ");
    printWithLineBreaks(comments[index].description);
    printf("\n");
    printf("Valoración: ......... %d\n\n", comments[index].rating);
    printf("Fecha: .............. %s\n\n",comments[index].commentDate);
    printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
}

void printCommentAdmin(const void *elements, int index)
{
    stComment *comments = (stComment*) elements;

    if(comments[index].deleted)
    {
        printf("\t\tDESACTIVADO\n\n");
    }

    printf("\n><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
    printf("ID: ................. %d\n", comments[index].commentId);
    printf("ID usuario: ......... %d\n", comments[index].userId);
    printf("ID libro: ........... %d\n", comments[index].bookId);
    printf("Titulo: ............. %s\n", comments[index].commentTitle);
    printf("Descripción: ........ ");
    printWithLineBreaks(comments[index].description);
    printf("Valoración: ......... %d\n", comments[index].rating);
    printf("Fecha: .............. %s\n", comments[index].commentDate);
    printf("Eliminado: .......... %s\n", comments[index].deleted ? "Si" : "No");
    printf("\n><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
}

int haveComments(stComment *comments, int totalComments, int idBook, stComment *handleComments)
{
    int numComments = 0;

    for(int i = 0; i<totalComments; i++)
    {
        if (comments[i].bookId == idBook)
        {
            handleComments[numComments] = comments[i];
            numComments++;
        }
    }

    return numComments;

}

int commentIndexById (stComment *comments, int id, int totalComments)
{
    int i = 0;

    while (i < totalComments)
    {
        if (comments[i].commentId == id)
        {
            return i;
        }
        i++;
    }

    return -1;
}

float changeRatingBook(stComment *comments, int totalComments, int idBook){
    int numComments = 0;
    float sumRating = 0;
    float rating;

    for(int i = 0; i < totalComments; i++){
        if(idBook == comments[i].bookId){
            sumRating += comments[i].rating;
            numComments++;
        }
    }

    if(numComments != 0){
        rating = (float) sumRating / numComments;
    } else {
        rating = 0;
    }

    return rating;
}

void deleteComment(int idComment, stComment comments[], int *totalComments){
    int indexComment = commentIndexById(comments, idComment, *totalComments);
    deleteFile(comments, sizeof(stComment), indexComment, *totalComments, COMMENTS);
    *totalComments = readFile(comments, sizeof(stComment), COMMENTS);
}

void deleteCommentsBook(stComment *comments, int *totalComments, int idBook)
{
    int count = *totalComments;

    for(int i = 0; i<count; i++)
    {
        if (comments[i].bookId == idBook)
        {
            deleteComment(comments[i].commentId, comments, totalComments);
        }
    }
}

void editComment(int idComment, stComment comments[], int totalComments){

    char option;
    int indexComment = commentIndexById(comments, idComment, totalComments);
    do{
        system("cls");
        printf("Dato que quiere editar: \n\n");

        printf("  1)  Editar titulo.\n");
        printf("  2)  Editar descripcion.\n");
        printf("  3)  Editar valoracion.\n");
        printf("esc)  Volver.\n");

        fflush(stdin);
        option = getch();

        switch(option){
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
    } while(option != 27);
}
