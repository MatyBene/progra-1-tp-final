#include "book.h"

/// Mockup libros (151)

stBook libros[] = {

    {1, "Cien a�os de soledad", "Editorial Sudamericana", "Gabriel Garc�a M�rquez", "Realismo m�gico", 2, 0},
    {2, "1984", "Secker & Warburg", "George Orwell", "Distop�a", 4, 0},
    {3, "El se�or de los anillos", "Minotauro", "J.R.R. Tolkien", "Fantas�a �pica", 3, 0},
    {4, "Don Quijote de la Mancha", "Real Academia Espa�ola", "Miguel de Cervantes", "Novela cl�sica", 2, 0},
    {5, "Harry Potter y la piedra filosofal", "Bloomsbury", "J.K. Rowling", "Fantas�a juvenil", 1, 0},
    {6, "Matar un ruise�or", "J. B. Lippincott & Co.", "Harper Lee", "Novela de aprendizaje", 5, 0},
    {7, "Crimen y castigo", "Editorial Elida", "Fyodor Dostoevsky", "Novela psicol�gica", 2, 0},
    {8, "Orgullo y prejuicio", "T. Egerton, Whitehall", "Jane Austen", "Novela rom�ntica", 3, 0},
    {9, "El alquimista", "HarperCollins", "Paulo Coelho", "Novela filos�fica", 5, 0},
    {10, "Los juegos del hambre", "Scholastic", "Suzanne Collins", "Ciencia ficci�n juvenil", 2, 0},
    {11, "El Principito", "Reynal & Hitchcock", "Antoine de Saint-Exup�ry", "Literatura infantil", 4, 0},
    {12, "Rayuela", "Editorial Sudamericana", "Julio Cort�zar", "Novela experimental", 3, 0},
    {13, "La Odisea", "Sin especificar", "Homero", "Epopeya", 2, 0},
    {14, "Moby Dick", "Harper & Brothers", "Herman Melville", "Novela de aventuras", 3, 0},
    {15, "Cr�nica de una muerte anunciada", "Editorial La Oveja Negra", "Gabriel Garc�a M�rquez", "Realismo m�gico", 1, 0},
    {16, "Anna Karenina", "The Russian Messenger", "Le�n Tolst�i", "Novela realista", 2, 0},
    {17, "La metamorfosis", "Kurt Wolff Verlag", "Franz Kafka", "Ficci�n absurda", 4, 0},
    {18, "El gran Gatsby", "Charles Scribner's Sons", "F. Scott Fitzgerald", "Novela rom�ntica", 2, 0},
    {19, "El perfume: historia de un asesino", "Diogenes Verlag", "Patrick S�skind", "Novela hist�rica", 3, 0},
    {20, "El c�digo Da Vinci", "Doubleday", "Dan Brown", "Novela de misterio", 1, 0},
    {21, "El nombre del viento", "DAW Books", "Patrick Rothfuss", "Fantas�a �pica", 1, 0},
    {22, "El laberinto de los esp�ritus", "Planeta", "Carlos Ruiz Zaf�n", "Novela g�tica", 3, 0},
    {23, "Sapiens: De animales a dioses", "Harper", "Yuval Noah Harari", "Ensayo hist�rico", 1, 0},
    {24, "El retrato de Dorian Gray", "Lippincott's Monthly Magazine", "Oscar Wilde", "Novela g�tica", 4, 0},
    {25, "El le�n, la bruja y el armario", "Geoffrey Bles", "C.S. Lewis", "Fantas�a juvenil", 2, 0},
    {26, "Los pilares de la Tierra", "William Morrow and Company", "Ken Follett", "Novela hist�rica", 5, 0},
    {27, "El poder del ahora", "Namaste Publishing", "Eckhart Tolle", "Autoayuda", 2, 0},
    {28, "Los hombres que no amaban a las mujeres", "Norstedts F�rlag", "Stieg Larsson", "Novela de misterio", 3, 0},
    {29, "La sombra del viento", "Editorial Planeta", "Carlos Ruiz Zaf�n", "Novela g�tica", 2, 0},
    {30, "La ciudad y los perros", "Seix Barral", "Mario Vargas Llosa", "Novela realista", 5, 0},
    {31, "El t�nel", "Sur", "Ernesto Sabato", "Novela psicol�gica", 3, 0},
    {32, "El viejo y el mar", "Charles Scribner's Sons", "Ernest Hemingway", "Novela corta", 2, 0},
    {33, "El m�dico", "Droemer Knaur", "Noah Gordon", "Novela hist�rica", 3, 0},
    {34, "El juego de Ender", "Tor Books", "Orson Scott Card", "Ciencia ficci�n", 2, 0},
    {35, "El jard�n secreto", "Heinemann", "Frances Hodgson Burnett", "Literatura infantil", 4, 0},
    {36, "La insoportable levedad del ser", "Gallimard", "Milan Kundera", "Novela filos�fica", 4, 0},
    {37, "La hoguera de las vanidades", "Farrar, Straus and Giroux", "Tom Wolfe", "Novela sat�rica", 5, 0},
    {38, "El amor en los tiempos del c�lera", "Editorial Sudamericana", "Gabriel Garc�a M�rquez", "Realismo m�gico", 5, 0},
    {39, "Las correcciones", "Farrar, Straus and Giroux", "Jonathan Franzen", "Novela contempor�nea", 5, 0},
    {40, "Mujercitas", "Roberts Brothers", "Louisa May Alcott", "Literatura juvenil", 5, 0},
    {41, "El cazador de sue�os", "Scribner", "Stephen King", "Novela de terror", 5, 0},
    {42, "El hombre en busca de sentido", "Beacon Press", "Viktor Frankl", "Psicolog�a", 1, 0},
    {43, "La naranja mec�nica", "William Heinemann", "Anthony Burgess", "Distop�a", 3, 0},
    {44, "El lobo estepario", "S. Fischer Verlag", "Hermann Hesse", "Novela existencialista", 5, 0},
    {45, "La ladrona de libros", "Alfred A. Knopf", "Markus Zusak", "Novela hist�rica", 5, 0},
    {46, "Rebeli�n en la granja", "Secker and Warburg", "George Orwell", "S�tira pol�tica", 5, 0},
    {47, "El alquimista", "HarperCollins", "Paulo Coelho", "Ficci�n espiritual", 5, 0},
    {48, "El gran dise�o", "Bantam Books", "Stephen Hawking", "Divulgaci�n cient�fica", 5, 0},
    {49, "El ruido y la furia", "Jonathan Cape and Harrison Smith", "William Faulkner", "Novela modernista", 5, 0},
    {50, "Los miserables", "A. Lacroix, Verboeckhoven & Cie.", "Victor Hugo", "Novela cl�sica", 5, 0},
    {51, "Revival", "Scribner", "Stephen King", "Terror", 5, 0},
    {52, "1984", "Secker & Warburg", "George Orwell", "Distop�a", 5, 0},
    {53, "Matar un ruise�or", "J. B. Lippincott & Co.", "Harper Lee", "Novela de aprendizaje", 5, 0},
    {54, "Harry Potter y la c�mara secreta", "Bloomsbury", "J.K. Rowling", "Fantas�a juvenil", 5, 0},
    {55, "Harry Potter y el prisionero de Azkaban", "Bloomsbury", "J.K. Rowling", "Fantas�a juvenil", 5, 0},
    {56, "Harry Potter y el c�liz de fuego", "Bloomsbury", "J.K. Rowling", "Fantas�a juvenil", 5, 0},
    {57, "Harry Potter y la Orden del F�nix", "Bloomsbury", "J.K. Rowling", "Fantas�a juvenil", 5, 0},
    {58, "Harry Potter y el misterio del pr�ncipe", "Bloomsbury", "J.K. Rowling", "Fantas�a juvenil", 5, 0},
    {59, "Harry Potter y las Reliquias de la Muerte", "Bloomsbury", "J.K. Rowling", "Fantas�a juvenil", 5, 0},
    {60, "�ngeles y demonios", "Atria Books", "Dan Brown", "Misterio", 5, 0},
    {61, "La conspiraci�n", "Atria Books", "Dan Brown", "Misterio", 5, 0},
    {62, "El s�mbolo perdido", "Doubleday", "Dan Brown", "Misterio", 5, 0},
    {63, "Inferno", "Doubleday", "Dan Brown", "Misterio", 5, 0},
    {64, "Origen", "Doubleday", "Dan Brown", "Misterio", 5, 0},
    {65, "El �ltimo deseo", "Bibli�polis", "Andrzej Sapkowski", "Fantas�a", 5, 0},
    {66, "La espada del destino", "Bibli�polis", "Andrzej Sapkowski", "Fantas�a", 5, 0},
    {67, "La sangre de los elfos", "Bibli�polis", "Andrzej Sapkowski", "Fantas�a", 5, 0},
    {68, "Tiempo de odio", "Bibli�polis", "Andrzej Sapkowski", "Fantas�a", 5, 0},
    {69, "Bautismo de fuego", "Bibli�polis", "Andrzej Sapkowski", "Fantas�a", 5, 0},
    {70, "La torre de la golondrina", "Bibli�polis", "Andrzej Sapkowski", "Fantas�a", 5, 0},
    {71, "La dama del lago", "Bibli�polis", "Andrzej Sapkowski", "Fantas�a", 5, 0},
    {72, "Hombre en llamas", "Arrow Books", "A. J. Quinnell", "Thriller", 5, 0},
    {73, "El anillo azul", "HarperCollins", "A. J. Quinnell", "Thriller", 5, 0},
    {74, "Cuerno negro", "HarperCollins", "A. J. Quinnell", "Thriller", 5, 0},
    {75, "Mensaje desde el infierno", "HarperCollins", "A. J. Quinnell", "Thriller", 5, 0},
    {76, "El asesino perfecto", "HarperCollins", "A. J. Quinnell", "Thriller", 5, 0},
    {77, "Los asesinos del anillo azul", "HarperCollins", "A. J. Quinnell", "Thriller", 5, 0},
    {78, "La venganza del cuerno negro", "HarperCollins", "A. J. Quinnell", "Thriller", 5, 0},
    {79, "Asesino", "HarperCollins", "A. J. Quinnell", "Thriller", 5, 0},
    {80, "Carrie", "Doubleday", "Stephen King", "Terror", 5, 0},
    {81, "El resplandor", "Doubleday", "Stephen King", "Terror", 5, 0},
    {82, "La zona muerta", "Viking Press", "Stephen King", "Terror", 5, 0},
    {83, "Ojos de fuego", "Viking Press", "Stephen King", "Terror", 5, 0},
    {84, "La danza de la muerte", "Viking Press", "Stephen King", "Terror", 5, 0},
    {85, "La larga marcha", "Signet Books", "Stephen King", "Terror", 5, 0},
    {86, "El fugitivo", "Signet Books", "Stephen King", "Terror", 5, 0},
    {87, "El misterio de Salem's Lot", "Doubleday", "Stephen King", "Terror", 5, 0},
    {88, "La c�pula", "Scribner", "Stephen King", "Terror", 5, 0},
    {88, "It", "Viking Press", "Stephen King", "Terror", 5, 0},
    {89, "Misery", "Viking Press", "Stephen King", "Terror", 5, 0},
    {90, "Eso", "Viking Press", "Stephen King", "Terror", 5, 0},
    {91, "La mitad oscura", "Viking Press", "Stephen King", "Terror", 5, 0},
    {92, "Los ojos del drag�n", "Viking Press", "Stephen King", "Terror", 5, 0},
    {93, "La tienda", "Viking Press", "Stephen King", "Terror", 5, 0},
    {94, "La historia de Lisey", "Scribner", "Stephen King", "Terror", 5, 0},
    {95, "La niebla", "Viking Press", "Stephen King", "Terror", 5, 0},
    {96, "Cementerio de animales", "Doubleday", "Stephen King", "Terror", 5, 0},
    {97, "La milla verde", "Signet Books", "Stephen King", "Terror", 5, 0},
    {98, "Insomnia", "Viking Press", "Stephen King", "Terror", 5, 0},
    {99, "Desesperaci�n", "Viking Press", "Stephen King", "Terror", 5, 0},
    {100, "El retrato de Rose Madder", "Viking Press", "Stephen King", "Terror", 5, 0},
    {101, "Corazones en la Atl�ntida", "Scribner", "Stephen King", "Terror", 5, 0},
    {102, "La Torre Oscura I: El pistolero", "Donald M. Grant, Publisher", "Stephen King", "Terror", 5, 0},
    {102, "La Torre Oscura II: La llegada de los tres", "Donald M. Grant, Publisher", "Stephen King", "Terror", 5, 0},
    {103, "La Torre Oscura III: Las tierras bald�as", "Donald M. Grant, Publisher", "Stephen King", "Terror", 5, 0},
    {104, "La Torre Oscura IV: Mago y Cristal", "Donald M. Grant, Publisher", "Stephen King", "Terror", 5, 0},
    {105, "La Torre Oscura V: Lobos del Calla", "Donald M. Grant, Publisher", "Stephen King", "Terror", 5, 0},
    {106, "La Torre Oscura VI: Canci�n de Susannah", "Donald M. Grant, Publisher", "Stephen King", "Terror", 5, 0},
    {107, "La Torre Oscura VII: La Torre Oscura", "Donald M. Grant, Publisher", "Stephen King", "Terror", 5, 0},
    {108, "Salem's Lot", "Doubleday", "Stephen King", "Terror", 5, 0},
    {109, "La expedici�n", "Doubleday", "Stephen King", "Terror", 5, 0},
    {110, "El juego de Gerald", "Viking Press", "Stephen King", "Terror", 5, 0},
    {111, "Carretera maldita", "Viking Press", "Stephen King", "Terror", 5, 0},
    {112, "La casa negra", "Scribner", "Stephen King", "Terror", 5, 0},
    {113, "Cell", "Scribner", "Stephen King", "Terror", 5, 0},
    {114, "La historia de Lisey", "Scribner", "Stephen King", "Terror", 5, 0},
    {115, "Duma Key", "Scribner", "Stephen King", "Terror", 5, 0},
    {116, "Bajo la c�pula", "Scribner", "Stephen King", "Terror", 5, 0},
    {117, "22/11/63", "Scribner", "Stephen King", "Terror", 5, 0},
    {118, "Doctor Sue�o", "Scribner", "Stephen King", "Terror", 5, 0},
    {119, "Joyland", "Hard Case Crime", "Stephen King", "Terror", 5, 0},
    {120, "Danza de Dragones", "Bantam Spectra", "George R.R. Martin", "Fantas�a �pica", 5, 0},
    {121, "El pr�ncipe Caspian", "Geoffrey Bles", "C.S. Lewis", "Fantas�a juvenil", 5, 0},
    {122, "La traves�a del Viajero del Alba", "Geoffrey Bles", "C.S. Lewis", "Fantas�a juvenil", 5, 0},
    {123, "La silla de plata", "Geoffrey Bles", "C.S. Lewis", "Fantas�a juvenil", 5, 0},
    {124, "El caballo y el muchacho", "Geoffrey Bles", "C.S. Lewis", "Fantas�a juvenil", 5, 0},
    {125, "El sobrino del mago", "Geoffrey Bles", "C.S. Lewis", "Fantas�a juvenil", 5, 0},
    {126, "La �ltima batalla", "Geoffrey Bles", "C.S. Lewis", "Fantas�a juvenil", 5, 0},
    {127, "Juego de Tronos", "Bantam Spectra", "George R.R. Martin", "Fantas�a �pica", 5, 0},
    {128, "Choque de Reyes", "Bantam Spectra", "George R.R. Martin", "Fantas�a �pica", 5, 0},
    {129, "Tormenta de Espadas", "Bantam Spectra", "George R.R. Martin", "Fantas�a �pica", 5, 0},
    {130, "Fest�n de Cuervos", "Bantam Spectra", "George R.R. Martin", "Fantas�a �pica", 5, 0},
    {131, "Danza de Dragones", "Bantam Spectra", "George R.R. Martin", "Fantas�a �pica", 5, 0},
    {132, "La Comunidad del Anillo", "Minotauro", "J.R.R. Tolkien", "Fantas�a �pica", 5, 0},
    {133, "Las Dos Torres", "Minotauro", "J.R.R. Tolkien", "Fantas�a �pica", 5, 0},
    {134, "El Retorno del Rey", "Minotauro", "J.R.R. Tolkien", "Fantas�a �pica", 5, 0},
    {135, "Crep�sculo", "Little, Brown and Company", "Stephenie Meyer", "Romance paranormal", 5, 0},
    {136, "Luna nueva", "Little, Brown and Company", "Stephenie Meyer", "Romance paranormal", 5, 0},
    {137, "Eclipse", "Little, Brown and Company", "Stephenie Meyer", "Romance paranormal", 5, 0},
    {138, "Amanecer", "Little, Brown and Company", "Stephenie Meyer", "Romance paranormal", 5, 0},
    {139, "El duque y yo", "Avon Books", "Julia Quinn", "Romance hist�rico", 5, 0},
    {140, "El vizconde que me am�", "Avon Books", "Julia Quinn", "Romance hist�rico", 5, 0},
    {141, "Te doy mi coraz�n", "Avon Books", "Julia Quinn", "Romance hist�rico", 5, 0},
    {142, "Seduciendo a Mr. Bridgerton", "Avon Books", "Julia Quinn", "Romance hist�rico", 5, 0},
    {143, "El coraz�n de una Bridgerton", "Avon Books", "Julia Quinn", "Romance hist�rico", 5, 0},
    {144, "Por un beso", "Avon Books", "Julia Quinn", "Romance hist�rico", 5, 0},
    {145, "El placer de la tentaci�n", "Avon Books", "Julia Quinn", "Romance hist�rico", 5, 0},
    {146, "Al filo de la medianoche", "Avon Books", "Julia Quinn", "Romance hist�rico", 5, 0},
    {147, "Buscando esposa", "Avon Books", "Julia Quinn", "Romance hist�rico", 5, 0},
    {148, "Una noche como esta", "Avon Books", "Julia Quinn", "Romance hist�rico", 5, 0},
    {149, "A Sir Phillip, con amor", "Avon Books", "Julia Quinn", "Romance hist�rico", 5, 0},
    {150, "El secreto de lady Danbury", "Avon Books", "Julia Quinn", "Romance hist�rico", 5, 0},
    {151, "El duque y la se�orita", "Avon Books", "Julia Quinn", "Romance hist�rico", 5, 0},
    {152, "Cuando la pasi�n espera", "Avon Books", "Julia Quinn", "Romance hist�rico", 5, 0},
    {153, "Espl�ndida pasi�n", "Avon Books", "Julia Quinn", "Romance hist�rico", 5, 0},
    {154, "El regreso de los Bridgerton", "Avon Books", "Julia Quinn", "Romance hist�rico", 5, 0}

};
