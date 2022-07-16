/* 
  Ejercicio 3 de Final 1 1C2022 Algo1 Camejo

  NO ARREGLADO

	Anita y Rogers e mudaron al interior y consiguieron una hermosa casa con un parque
	enorrrrrme donde los 101 dálmatas pueden ser felices y correr en libertad

	Se tiene un archivo de coordenadas llamado coordenadas.csv donde está cada una de las posiciones de los dálmatas en el parque.

	Se pide
		1. Generar un archivo distancias.txt que contenga la información de los 2 dálmatas que
		   están mas cerca entre ellos y de los 2 dálmatas que esten más alejados
	
	Ejemplo
		Aclaracion: las coordenadas pueden ser números con coma.
	
	coordenadas.csv

		5;8
		6.5;15
		2;2
		0;0
		45;20
	
	distancias.txt

		Más cerca: (0;0) - (2;2)
		Más alejados: (0;0) - (45;20)

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_BUFFER_SALIDA 50
#define MAX_BUFFER_ENTRADA 10000
#define MAX_DALMATAS 101

double calcular_distancia(double ax, double ay, double bx, double by){
	double sub_res_x = (ax>bx)? ax-bx : bx-ax;
	double sub_res_y = (ay>by)? ay-by : by-ay;
	return sqrt(pow(sub_res_y, 2)+pow(sub_res_x, 2));
}

void analizar_distancias(char menor_distancia[MAX_BUFFER_SALIDA], char mayor_distancia[MAX_BUFFER_SALIDA], double x[MAX_DALMATAS], double y[MAX_DALMATAS], int tope){
	int resultado = (tope%2==0)? tope/2 : (tope/2)+1;
	double distancia_menor = 1000, distancia_mayor = 0;
	for(int i = 0; i<resultado; i++){
		for(int k = 0; k<tope; k++){
			if(i != k){
				if(distancia_mayor < calcular_distancia(x[i], y[i], x[k], y[k])){
					sprintf(mayor_distancia, "Mas alejados: (%i;%i) - (%i;%i)", (int)x[i], (int)y[i], (int)x[k], (int)y[k]);
				}
				if(distancia_menor > calcular_distancia(x[i], y[i], x[k], y[k])){
					sprintf(menor_distancia, "Mas cerca: (%i;%i) - (%i;%i)\n", (int)x[i], (int)y[i], (int)x[k], (int)y[k]);
				}
			}
		}
	}
}

void obtener_distancias(char menor_distancia[MAX_BUFFER_SALIDA], char mayor_distancia[MAX_BUFFER_SALIDA], FILE *leer_archivo){
	int i, tope = 0;
	double x[MAX_DALMATAS], y[MAX_DALMATAS];
	char buffer[MAX_BUFFER_ENTRADA], *ptr;
	for(i = 0; i < MAX_DALMATAS; i++){
		fgets(buffer, MAX_BUFFER_ENTRADA, leer_archivo);
		if(strcmp(buffer, "\0") != 0){
			ptr = strtok(buffer, ";");
			x[i] = atof(ptr);
			ptr = strtok(buffer, "\n");
			y[i] = atof(ptr);
			tope ++;
		}
	}
	analizar_distancias(menor_distancia, mayor_distancia, x, y, tope);
}

void cargar_distancias(char menor_distancia[MAX_BUFFER_SALIDA], char mayor_distancia[MAX_BUFFER_SALIDA], FILE* escribir_archivo){
	fprintf(escribir_archivo, "%s%s", menor_distancia, mayor_distancia);
}

int main(){
	FILE *leer_archivo = fopen("archivos/coordenadas.csv", "r");
	FILE *escribir_archivo = fopen("archivos/distancias.txt", "w");
	char menor_distancia[MAX_BUFFER_SALIDA], mayor_distancia[MAX_BUFFER_SALIDA], file_check[MAX_BUFFER_ENTRADA];
	if(leer_archivo != NULL){
		fgets(file_check, MAX_BUFFER_ENTRADA, leer_archivo);
		if(strcmp(file_check, "\0") != 0){
			obtener_distancias(menor_distancia, mayor_distancia, leer_archivo);
			cargar_distancias(menor_distancia, mayor_distancia, escribir_archivo);		
		}
		fclose(leer_archivo);
	}
	fclose(escribir_archivo);
	return 0;
}