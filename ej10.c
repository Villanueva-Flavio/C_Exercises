#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NOMBRE 100
#define MAX_AUTOR 100
#define MAX_LIBROS 50

typedef struct libro{
    char nombre[MAX_NOMBRE];
    char autor[MAX_AUTOR];
    int cant_paginas;
}libro_t;


void cargar_libros_biblioteca(libro_t biblioteca[MAX_LIBROS], int* tope){

    strcpy(biblioteca[*tope].nombre, "Cementerio de animales");
    strcpy(biblioteca[*tope].autor, "S king");
    biblioteca[*tope].cant_paginas = 500;
    (*tope) ++;

    strcpy(biblioteca[*tope].nombre, "Libro 2");
    strcpy(biblioteca[*tope].autor,"pepito");
    biblioteca[*tope].cant_paginas = 200;
    (*tope) ++;

    strcpy(biblioteca[*tope].nombre, "libro 3");
    strcpy(biblioteca[*tope].autor,"willyrex");
    biblioteca[*tope].cant_paginas = 50;
    (*tope) ++;
    
    strcpy(biblioteca[*tope].nombre, "libro 4");
    strcpy(biblioteca[*tope].autor,"willyrex");
    biblioteca[*tope].cant_paginas = 90;
    (*tope) ++;
}

void cargar_libros_biblioteca_actual(libro_t biblioteca_actual[MAX_LIBROS], int* tope){

    strcpy(biblioteca_actual[*tope].nombre, "Cementerio de animales");
    strcpy(biblioteca_actual[*tope].autor, "S king");
    biblioteca_actual[*tope].cant_paginas = 500;
    (*tope)++;

    strcpy(biblioteca_actual[*tope].nombre, "libro 3");
    strcpy(biblioteca_actual[*tope].autor,"willyrex");
    biblioteca_actual[*tope].cant_paginas = 50;
    (*tope)++;
}

bool son_libros_iguales(libro_t libro1, libro_t libro2){
    return ((strcmp(libro1.nombre, libro2.nombre) == 0) && (strcmp(libro1.autor, libro2.autor) == 0) && libro1.cant_paginas == libro2.cant_paginas)? true:false;
}

void cargar_prestados(libro_t biblioteca[MAX_LIBROS], int tope_iniciales, libro_t libros_prestados[MAX_LIBROS], int* tope_prestados, libro_t biblioteca_actual[MAX_LIBROS], int tope_actuales){
    int i, j;
    bool encontrado = false;
    printf("%i %i\n", tope_iniciales, tope_actuales);
    for(i = 0; i < tope_iniciales; i++){
        for(j = 0; j < tope_actuales; j++){
            if(son_libros_iguales(biblioteca[i], biblioteca_actual[j])){
                encontrado = true;
            }
        }
        if(encontrado == false){
            strcpy(libros_prestados[*tope_prestados].nombre, biblioteca[i].nombre);
            strcpy(libros_prestados[*tope_prestados].autor, biblioteca[i].autor);
            libros_prestados[*tope_prestados].cant_paginas = biblioteca[i].cant_paginas;
            (*tope_prestados)++;
        }
        encontrado = false;
    }
}


int main(){

    libro_t biblioteca[MAX_LIBROS];
    libro_t biblioteca_actual[MAX_LIBROS];
    libro_t libros_prestados[MAX_LIBROS];

    int tope_iniciales = 0;
    int tope_actuales = 0;
    int tope_prestados = 0;

    cargar_libros_biblioteca(biblioteca, &tope_iniciales);
    cargar_libros_biblioteca_actual(biblioteca_actual, &tope_actuales);
    cargar_prestados(biblioteca, tope_iniciales, libros_prestados, &tope_prestados , biblioteca_actual, tope_actuales);
    printf("tope p %i\n", tope_prestados);

    
        for(int i = 0; i < tope_prestados; i++){
        printf("Nombre prestado %s\n", libros_prestados[i].nombre);
        printf("Autor prestado %s\n", libros_prestados[i].autor);
        printf("Paginas prestado %i\n\n", libros_prestados[i].cant_paginas);
        printf("%i\n", i);
    } 
    

    return 0;
}