#include "coment.h"
#include "coment-data.h"
#include "../menu.h"

void commentRegister(stComment comments[], int *totalComments, int idUser, int idBook) /// PERMITE CREAR UN NUEVO COMENTARIO
{
    comments[*totalComments].commentId = firstFreeIdComment(comments, *totalComments);
    comments[*totalComments].userId = idUser;
    comments[*totalComments].bookId = idBook;
    newCommentTitle(comments, *totalComments);
    newDescription(comments, *totalComments);
    newRating(comments, *totalComments);
    newDate(comments, *totalComments);
    comments[*totalComments].deleted = 0;

    appendFile(comments, sizeof(stComment), *totalComments, COMMENTS);
    (*totalComments)++;
}

void printComment(const void *elements, int index) /// MUESTRA UN COMENTARIO
{
    stComment *comments = (stComment*) elements;

    printf("Titulo: ............. %s\n\n", comments[index].commentTitle);
    printf("Descripción: ........ ");
    printWithLineBreaks(comments[index].description, 40);
    printf("\n");
    printf("Valoración: ......... %d\n\n", comments[index].rating);
    printf("Fecha: .............. %s\n\n",comments[index].commentDate);
    printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
}

void printCommentAdmin(const void *elements, int index) /// MUESTRA UN COMENTARIO PARA LOS ADMIN
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
    printWithLineBreaks(comments[index].description, 40);
    printf("Valoración: ......... %d\n", comments[index].rating);
    printf("Fecha: .............. %s\n", comments[index].commentDate);
    printf("Eliminado: .......... %s\n", comments[index].deleted ? "Si" : "No");
    printf("\n><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
}

int haveComments(stComment *comments, int totalComments, int idBook, stComment *handleComments) /// EVALUA QUE UN LIBRO TENGA COMENTARIOS
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

int commentIndexById (stComment *comments, int id, int totalComments) /// DEVUELVE LA POSICION DE UN COMENTARIO POR SU ID
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

float changeRatingBook(stComment *comments, int totalComments, int idBook) /// CAMBIA LA VALORACION DE UN LIBRO A PARTIR DE SUS COMENTARIOS ASOCIADOS
{
    int numComments = 0;
    float sumRating = 0;
    float rating;

    for(int i = 0; i < totalComments; i++)
    {
        if(idBook == comments[i].bookId)
        {
            sumRating += comments[i].rating;
            numComments++;
        }
    }

    if(numComments != 0)
    {
        rating = (float) sumRating / numComments;
    }
    else
    {
        rating = 0;
    }

    return rating;
}

void deleteComment(int idComment, stComment comments[], int *totalComments) /// BORRA UN COMENTARIO PERMANENTEMENTE
{
    int indexComment = commentIndexById(comments, idComment, *totalComments);
    deleteFile(comments, sizeof(stComment), indexComment, *totalComments, COMMENTS);
    *totalComments = readFile(comments, sizeof(stComment), COMMENTS);
}

void deleteCommentsBook(stComment *comments, int *totalComments, int idBook) /// ELIMINA TODOS LOS COMENTARIOS ASOCIADOS A UN LIBRO
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
