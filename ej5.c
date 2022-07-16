/* 
  Ejercicio 2 de Final 1 1C2022 Algo1 Camejo

  NO ARREGLADO
  
    Por fin encontramos el tesorod espués de tanta búsqueda, finalmente vamos a abrirlo yyyy...
    "Por favor ingrese la contraseña.". Estamos perdidos!
    Nos dimos cuenta que atrás del mapa hay unas pistas... a ver que dice:
        
        Si el tesoro es lo que quieres,
        una contraseña es lo que tienes,
        en una matriz dentro de un archivo,
        con un cálculo muy intensivo.
    
    Se tiene un archivo pistas.csv donde la primer linea nos dice la dimensión de la matriz (se sabe
    que es cuadrada por lo que sólo será un número), seguida de una matriz de enteros:

    Se pide
        1. Obtener los datos de la matriz, y luego escribir en otro archivo contrasenia.txt, el vector
            resultante de la resta de la diagonal principal de la matriz, con la diagonal inversa.

    Ejemplo
        pista.csv

        3
        5;8;9
        3;6;3
        2;1;4
    
    Con la matriz del ejemplo, 3 es la dimensión de la matriz, (5, 6, 4) es la diagonal principal y
    (9, 6, 2) la diagonal inversa. El 5 debería restarse con el 9, el 6 con el 6 (ambos son el centro), y
    el 4 con el 2, dando así, el vector resultante: (-4, 0, 2)

        contrasenia.txt

        (-4;0;2)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100
#define MAX_BUFFER 10000

void cargar_matriz(FILE* leer_archivo, int matriz[MAX_SIZE][MAX_SIZE], int* tope){
	char *ptr, buffer[MAX_BUFFER];
	int i, k;
	fgets(buffer, MAX_BUFFER, leer_archivo);
	ptr = strtok(buffer, "\n");
	*tope = atoi(ptr);
	for(i = 0; i < *tope; i++){
		fgets(buffer, MAX_BUFFER, leer_archivo);
		if(strcmp(buffer, "\0") != 0){
			for(k = 0; k < *tope; k++){
				ptr = strtok(buffer, ";");
				matriz[i][k] = atoi(ptr);
			}
		}
	}
}

void desencriptar(int matriz[MAX_SIZE][MAX_SIZE], int contrasenia[MAX_SIZE], int tope){
	for(int i = 0; i<tope; i++){
		contrasenia[i] = matriz[i][i] - matriz[(tope-1)-i][i];
		printf("%i\n", contrasenia[i]);
	}
}

void guardar_contrasenia(FILE *escribir_archivo, int contrasenia[MAX_SIZE], int tope){
	int i;
	fprintf(escribir_archivo, "(");
	for(i = 0; i<tope; i++){
		fprintf(escribir_archivo, "%i%s", contrasenia[i], (i==tope-1)?"":";");
	}
	fprintf(escribir_archivo, ")");
}

int main(){
	int tope, contrasenia[MAX_SIZE], matriz[MAX_SIZE][MAX_SIZE];
	FILE *leer_archivo = fopen("pista.csv", "r");
	FILE *escribir_archivo = fopen("contrasenia.txt", "w");
	char file_check[MAX_BUFFER];
	
	if(leer_archivo != NULL){
		fgets(file_check, MAX_BUFFER, leer_archivo);
		if(strcmp(file_check, "/0") != 0){
			cargar_matriz(leer_archivo, matriz, &tope);
			desencriptar(matriz, contrasenia, tope);
			guardar_contrasenia(escribir_archivo, contrasenia, tope);
		}
		fclose(leer_archivo);
	}
	fclose(escribir_archivo);
	return 0;
}