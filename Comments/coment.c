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

    appendFile(comments, sizeof(stComment), *totalComments, COMMENTS);
    (*totalComments)++;
}

void printComment(const void *elements, int index)
{
    stComment *comments = (stComment*) elements;

    printf("Titulo: ....... %s\n", comments[index].commentTitle);
    printf("IDLIBRO: ....... %d\n", comments[index].bookId);
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

int printCommentsBook(stComment *comments, int totalComments, int idBook)
{
    int flag = 0;

    for(int i = 0; i<totalComments; i++)
    {
        if (comments[i].bookId == idBook)
        {
            printComment(comments,i);
            flag = 1;
        }
    }

    return flag;

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

void deleteComment(int indexComment, stComment comments[], int *totalComments){
    deleteFile(comments, sizeof(stComment), indexComment, *totalComments, COMMENTS);
    *totalComments = readFile(comments, sizeof(stComment), COMMENTS);
}

void deleteCommentsBook(stComment *comments, int *totalComments, int idBook)
{

    for(int i = 0; i<*totalComments; i++)
    {
        if (comments[i].bookId == idBook)
        {
            deleteComment(i, comments, totalComments);
        }
    }
}
