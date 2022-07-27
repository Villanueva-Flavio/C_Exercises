/*
      Ejercicio 2 de Final 2 1C2022 Algo1 Camejo

    Woody, como ya sabemos, es el responsable de que Forky no crea basura y aprenda todo
    sobre la vida diaria. Hoy, toca una nueva lección, que es la de aprender los números y poder
    ordenarlos

    Se tiene un archivo donde se recibirán hasta 50 números y cada uno no será mayor a 100 ni 
    menor a 0

    Se pide

        1. Generar un archivo con los números que estaban repetidos en el primer archivo, ordenados
            de mayor a menor

    Ejemplo

        Recibiendo el archivo:
            numeros.txt

                1
                7
                34
                9
                7
                7
                1
                12
                9
                1
        
        Se obtiene:
            ordenados.txt

                9
                7
                1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NUMEROS 50 
const int ERROR = -1;
//genrear un archivo con los numeros que estaban repetidos en el primer archivo, ordenados de mayor a menor 

void ordenar_vector(int numeros[MAX_NUMEROS], int* tope){
    int aux;
    for(int i = 1; i < tope; i++){
        for(int j = 0; j <tope - i; j++){
            if(numeros[j] < numeros[j+1]){
                aux = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = aux;
            }
        }
    }

}

int main(int argc, char* argv[]){

    FILE* f_numeros = fopen("numeros.txt", "r");
    if(f_numeros == NULL){
        perror("No se pudo abrir el archivo\n");
        return ERROR;
    }

    FILE* f_numeros_repetidos = fopen("numeros_repetidos.txt", "w");
    if(f_numeros_repetidos == NULL){
        perror("No se pudo abrir el archivo\n");
        fclose(f_numeros);
        return ERROR;
    }

    int numeros[MAX_NUMEROS];
    int tope = 0;

    int leidos = fscanf(f_numeros, "%i\n", numeros[tope]);
    while(leidos == 1){
        leidos = fscanf(f_numeros, "%i\n", numeros[tope]);
        tope++;
    }

    for(int i = 0; i <= tope; i++){
        printf("numero %i\n", numeros[i]);
    }



    fclose(f_numeros);
    fclose(f_numeros_repetidos);

    return 0;
}