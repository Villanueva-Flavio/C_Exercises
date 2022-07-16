/*
Dexter está queriendo continuar la partida de la batalla naval que estaba jugando contra su Computadora y necesita cargar la matriz del terreno con las jugadas.
Para eso tiene guardados 2 archivos, por un lado tiene uno con las coordenadas de todos los barcos y por otro tiene un archivo con las coordenadas de los tiros 
que su contrincante le hizo.
Ambos son archivos de texto y tienen el siguiente formato.
    fila;columna
Se pide
1. Dados 2 archivos de texto,uno con los barcos y otro con los tiros, crear un procedimiento que devuelva la matriz cargada con la partida para que sigan jugando. 
*/

/*
    Toma de notas:
        formato: fila;columna
        2 archivos
            -barcos
            -disparos
        formato de juego: matricial
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BARCOS 10
#define MAX_DISPAROS 1000
#define MAX_SIZE 10
#define MAX_BUFFER 10000
#define BARCO 'B'
#define DISPARO 'D'

void cargar_partida(char juego[MAX_SIZE][MAX_SIZE], FILEleer_archivo, char solicitud){
    char buffer[MAX_BUFFER], chr; //Defino un buffer maximo y un puntero al comienzo de la fila de string del archivo
    int iteraciones = (solicitud == BARCO)? MAX_BARCOS:MAX_DISPAROS, fil, col;
    for(int i = 0; i < iteraciones; i++){
        fgets(buffer, MAX_BUFFER, leer_archivo); // Obtengo la siguiente fila de datos en string del archivo
        if(chr == NULL){
            i = iteraciones; // Corto el for si no hay datos para evitar segfault
            continue;
        }
        chr = strtok(chr, ";"); // chr vale el string antes del ;
        fil = atoi(chr); // transformo el str en int y lo guardo en un dato
        chr = strtok(chr, "\n");
        col = atoi(chr);
        juego[fil][col] = (solicitud == BARCO)? BARCO:DISPARO; // guardo el dato en el juego
    }
}

int main(){
    char juego[MAX_SIZE][MAX_SIZE];
    FILE *leer_archivo = fopen("archivos/barcos.txt", "r");
    cargar_partida(juego, leer_archivo, BARCO); //Cargo la posicion de todos los barcos
    cargar_partida(juego, leer_archivo, DISPARO); //Cargo la posicion de todos los disparos y superponen los barcos para eliminarlos
    fclose(leer_archivo);
    return 0;
}