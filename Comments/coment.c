#include "coment.h"
#include "coment-data.h"

void commentRegister(stComment comments[], int *index)
{
    comments[*index].commentId = *index + 1;
    newCommentTitle(comments, *index);
    newDescription(comments, *index);
    newRating(comments, *index);
    newDate(comments, *index);
    (*index)++;
}

void printComment(stComment comments[], int index)
{
    printf("\n><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
    printf("Titulo: ....... %s\n", comments[index].commentTitle);
    printf("Descripción: .. %s\n", comments[index].description);
    printf("Valoración: ... %d\n", comments[index].rating);
    printf("Fecha: ........ %s\n",comments[index].commentDate);
}

