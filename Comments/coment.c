#include "coment.h"
#include "coment-data.h"

void commentRegister(stComment comments[], int *index)
{
    comments[*index].commentId = *index + 1;
    newCommentTitle(comments, *index);
    newDescription(comments, *index);
    newRating(comments, *index);
    newDate(comments, *index);
    comments[*index].deleted = 0;
    (*index)++;
}

void printComment(const void *element)
{
    stComment *comment = (stComment*) element;

    printf("\n><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
    printf("Titulo: ....... %s\n", comment->commentTitle);
    printf("Descripción: .. %s\n", comment->description);
    printf("Valoración: ... %d\n", comment->rating);
    printf("Fecha: ........ %s\n",comment->commentDate);
}

void printCommentAdmin(const void *element)
{
    stComment *comment = (stComment*) element;

    printf("\n><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
    printf("ID: ........... %d\n", comment->commentId);
    printf("Titulo: ....... %s\n", comment->commentTitle);
    printf("Descripción: .. %s\n", comment->description);
    printf("Valoración: ... %d\n", comment->rating);
    printf("Fecha: ........ %s\n", comment->commentDate);
    printf("Eliminado: .... %s\n", comment->deleted ? "Si" : "No");
}

