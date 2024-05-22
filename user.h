#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

typedef struct{
    char calle[50];
    int altura;
    int cp;
    char ciudad[100];
    char localidad[50];
    char pais[100];
} stDomicilio;

typedef struct{
    int idUsuario;
    char email[100];
    char password[20];
    char username[20];
    int esAdmin;  /// 1 = si  0 = no
    char genero;
    char fechaNacimiento[20];  /// o se puede hacer con dia, mes, anio.
    int librosFavoritos[50]; /// se van a guardar los id de los libros favs.
    char dni[10];
    stDomicilio domicilio;
    int eliminado; /// 0 si está activo - 1 si está eliminado
}stUsuario;


#endif // USER_H_INCLUDED
