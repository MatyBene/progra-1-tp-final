#include "coment.h"
#include "coment-data.h"

void commentRegister(stComment comments[], int *index, int idUser, int idBook)
{
    comments[*index].commentId = *index + 1;
    comments[*index].userId = idUser;
    comments[*index].bookId = idBook;
    newCommentTitle(comments, *index);
    newDescription(comments, *index);
    newRating(comments, *index);
    newDate(comments, *index);
    comments[*index].deleted = 0;
    (*index)++;
}

void printComment(const void *elements, int index)
{
    stComment *comments = (stComment*) elements;

//    printf("\n\nPRINTCOMMENT: \n");
//    printf("INDICE COMENTARIO: %d\n\n", index);

    printf("Titulo: ....... %s\n", comments[index].commentTitle);
    printf("Descripción: .. %s\n", comments[index].description);
    printf("Valoración: ... %d\n", comments[index].rating);
    printf("Fecha: ........ %s\n",comments[index].commentDate);
    printf("\n><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
}

void printCommentAdmin(const void *elements, int index)
{
    stComment *comments = (stComment*) elements;

    printf("\n><><><><><><><><><><><><><><><><><><><><><><><><\n");
    printf("ID: ........... %d\n", comments[index].commentId);
    printf("ID usuario: ........... %d\n", comments[index].userId);
    printf("ID libro: ........... %d\n", comments[index].bookId);
    printf("Titulo: ....... %s\n", comments[index].commentTitle);
    printf("Descripción: .. %s\n", comments[index].description);
    printf("Valoración: ... %d\n", comments[index].rating);
    printf("Fecha: ........ %s\n", comments[index].commentDate);
    printf("Eliminado: .... %s\n", comments[index].deleted ? "Si" : "No");
    printf("\n><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
}

void printCommentsBook(stComment *comments, int totalComments, int idBook)
{

    for(int i = 0; i<totalComments; i++)
    {
        if (comments[i].bookId == idBook)
        {
            printComment(comments,i);
        }
    }
}

