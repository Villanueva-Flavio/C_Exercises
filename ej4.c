/*
  Ejercicio 1 de Final 1 1C2022 Algo1 Camejo

  NO ARREGLADO
  
    Oh no! Russell y Carl tienen peso de más en la casa de Up y se estan cayendo! Te animás a
    ayudarlos a encontrar los globos con más presión para que puedan inflarlos un poco más, y
    puedan elevarse?

    Se tiene un archivo presiones.csv donde se encuentra el color de cada globo, seguido de la presión del mismo.

    Se pide

    1. Obtener todos los globos que tengan la presión mínima, y escribirla en un archivo nuevo, globos_a_inflar.csv

    Ejemplo
    Recibiendo el archivo:

    presiones.csv

    rojo;21
    negro;12
    verde;20
    rosa;12
    violeta;17

    Se obtiene:
    globos_a_inflar.csv

    negro;12
    rosa;12

    Aclaración: El ejercicio fue realizado con fines prácticos de programación, No aceptamos quejas sobre química.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INDICES 1000
#define MAX_BUFFER 10000
#define MAX_PRESION 100000
#define MAX_COLOR 20

// rojo;21

int buscar_presion_minima(int presiones[MAX_INDICES], int tope){
    int resultado = MAX_PRESION;
    for(int i = 0; i < tope; i++){
        resultado = (presiones[i] < resultado)? presiones[i]:resultado;
    }
    return resultado;
}

void guardar_globos(int destino[MAX_INDICES], int fuente[MAX_INDICES], int tope, int presion){
    int i, k = 0;
    for(i = 0; i < tope; i++){
        if(fuente[i] == presion){
            destino[k] = i;
            k++;
        }
    }
}

void obtener_lista_de_globos(FILE *leer_archivo, int *tope, int presiones[MAX_INDICES]){
    char *ptr, buffer[MAX_BUFFER];
    int i, k = 0;
    for(i = 0; i < MAX_INDICES; i++){
        fgets(buffer, MAX_BUFFER, leer_archivo);
        if(strcmp(buffer, "\0") == 0){
            i = MAX_INDICES;
            continue;
        }
        ptr = strtok(buffer, ";");
        ptr = strtok(buffer, "\n");
        presiones[k] = atoi(ptr);
        k++;
    }
}

void buscar_globos(FILE *leer_archivo, int indices[MAX_INDICES], int* tope){
    int presiones[MAX_INDICES];
    obtener_lista_de_globos(leer_archivo, tope, presiones);
    guardar_globos(indices, presiones, *tope, buscar_presion_minima(presiones, *tope));
}

bool corresponde_indice(int i, int indices[MAX_INDICES], int tope){
    bool resultado = false;
    for(int i = 0; i < tope; i++){
        if(indices[i] == i){
            resultado = true;
            i = tope;
        }
    }
    return resultado;
}

void anotar_globos_a_inflar(FILE *escribir_archivo, FILE *leer_archivo, int indices[MAX_INDICES], int tope){
    int i, presion;
    char *ptr, buffer[MAX_BUFFER], color[MAX_COLOR];
    for(i = 0; i < tope; i++){
        fgets(buffer, MAX_BUFFER, leer_archivo);
        if(corresponde_indice(i, indices, tope)){
            ptr = strtok(buffer, ";");
            strcpy(ptr, color);
            ptr = strtok(buffer, "\n");
            presion = atoi(ptr);
        }
        fprintf(escribir_archivo, "%s;%i\n", color, presion);
    }
}

int main(){
    int indices[MAX_INDICES], tope = 0;
    FILE *leer_archivo = fopen("presiones.csv", "r");
    FILE *escribir_archivo = fopen("globos_a_inflar.csv", "w");
    char file_check[MAX_BUFFER];
    if(leer_archivo != NULL){
        fgets(file_check, MAX_BUFFER, leer_archivo);
        if(strcmp(file_check, "\0") != 0){
            buscar_globos(leer_archivo, indices, &tope);
            anotar_globos_a_inflar(escribir_archivo, leer_archivo, indices, tope);
        }
        fclose(leer_archivo);
    }
    fclose(escribir_archivo);
    return 0;
}