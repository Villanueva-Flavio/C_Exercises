// Ejercicio 2 de Final 1 1C2022 Algo1 Camejo

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