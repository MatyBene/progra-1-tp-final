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

void printComment(const void *elements, int index)
{
    stComment *comments = (stComment*) elements;

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
    printf("Titulo: ....... %s\n", comments[index].commentTitle);
    printf("Descripción: .. %s\n", comments[index].description);
    printf("Valoración: ... %d\n", comments[index].rating);
    printf("Fecha: ........ %s\n", comments[index].commentDate);
    printf("Eliminado: .... %s\n", comments[index].deleted ? "Si" : "No");
    printf("\n><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
}

