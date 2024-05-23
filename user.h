#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

typedef struct{
    char street[50];
    int number;
    int zipCode;
    char city[100];
    char locality[50];
    char country[100];
} stAddress;

typedef struct{
    int userId;
    char email[100];
    char password[20];
    char username[20];
    int isAdmin;  /// 1 = si  0 = no
    char gender;
    char birthDate[20];   /// o se puede hacer con dia, mes, anio.
    int favoriteBooks[50];  /// se van a guardar los id de los libros favs.
    char ssn[10];
    stAddress address;
    int deleted;  /// 0 si está activo - 1 si está eliminado
} stUser;

void userRegister(stUser *users);
int emailOk (char *mail, stUser *users);
int validEmail(char *email);
int existingEmail(char *email, stUser *users);
void getPass(char *pass);
int validPassword(char *pass);
int matchPassword(char *pass1, char *pass2);

#endif // USER_H_INCLUDED
