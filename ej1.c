/*
Ed, Edd y Eddy caminaban por el vecindario y quedaron fascinados al ver como a un adolescente le quedaba un piercing en la ceja.
Decidieron que iban a hacerse uno cada uno, pero antes, tenían que probarlo en alguien que no sienta dolor... Tablón
Como toda actividad en el barrio, por insignificante que parezca se convierte en un gran evento, decidieron que el clavo a elegir saldria de una competencia y que el dueño del clavo elegido
será coronado como Rey del Barrio por toda la semana
Ed, Edd y Eddy corrieron a jungar clavos y cada uno de ellos creó su propio vector de clavos


typedef struct clavo{
    int largo;
    int dobladez;
    bool oxidado;
}clavo_t;

El ganador de la competencia se determinará de la siguiente manera:

Variante 1
* Ed decidió entre los clavos que se encuentran en posiciones pares de su vector
* Edd decidió entre los clavos que se encuentran en posiciones impares de su vector
* Eddy decidio elegir entre los clavos que se encuentran en cualquier posicion de su vector
* Cada uno de ellos, eligirá el clavo mas largo
* De esos 3 clavos, el elegido para usar como piercing de tablón será el menos doblado.

1. Crear una funcion que muestre por pantalla el nombre del Rey del barrio y la posicion del clavo ganador

*/
#include <stdlib.h>
#include <stdio.h>

#define ED 'E'
#define EDD 'D'
#define EDDY 'Y'
#define MAX_CLAVOS 100

typedef struct clavo{
    int largo;
    int dobladez;
    bool oxidado;
}clavo_t;

int swap_clavos(clavo_t clavos[MAX_CLAVOS], int indice1, int indice2){
    clavo_t clavo_aux;
    clavos[indice1] = clavos[indice2]; // swapeo y
    clavos[indice2].largo = 0; // borro el clavo agarrado
    clavos[indice2].dobladez = 0;
}

int clavo_elegido(char personaje, clavo_t clavos[MAX_CLAVOS]){
    int i = (personaje == EDD)? 1:0; // Si es EDD es impar, si no, es par
    int iterador = (personaje == EDDY)? 1:2; // si es eddy elige todo, si no, cada 2
    int resultado = 0, indice;
    for(i; i < MAX_CLAVOS; i+=iterador){
        if(clavos[i].largo > resultado){
            resultado = clavos[i].largo;
            indice = i; // guardo el indice del clavo para agarrarlo
            swap_clavos(clavos, i, MAX_CLAVOS-1);
        }
    }
    return indice,
}

int comparar_rey(int a, int b, int c){
    int resultado = (a > b)? a:b; // comparo si es a o b
    return (a > c)? a:c; // despues si es a o c
}

char ver_rey_del_barrio(clavo_t clavos[MAX_CLAVOS]){
    char rey;
    int clavo_de_ed = clavo_elegido(ED, clavos); // Cada uno elige su clavo
    int clavo_de_edd = clavo_elegido(EDD, clavos);
    int clavo_de_eddy = clavo_elegido(EDDY, clavos);
    return comparar_rey(clavo_de_ed, clavo_de_edd, clavo_de_eddy);
}

int main(){
    clavo_t clavos[MAX_CLAVOS];
    // Rellenarias los clavos
    char rey = ver_rey_del_barrio(clavos);
    printf("El rey es %c", rey);
    return 0;
}
