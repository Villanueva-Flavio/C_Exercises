/*
    Coraje tuvo una buena caza de huesos durante sus vacaciones. Recolectó taaantos taaaantos huesos, que tuvo que hacer un 
archivo de texto llamado huesitos.csv para poder guardar la información sobre estos. El archivo se 
encuentra ordenado por zona descendentemente, luego por fecha ascendentemente, y finalmente por hueso alfabéticamente.
    Ahora que ya está tranquilo en su casa, antes de enterrarlos, quiere clasificarlos para tener un mayor control, y 
saber hasta cuando los puede comer sin que le caigan mal. Cómo anduvo por muchos lados, primero le gustaría clasificarlos 
por lugar y luego por fecha. Se pide

1.Clasificar a los huesos agrupados primero por zona en dónde los encontró, y luego por fecha, como se muestra a continuación:
 
 ---------------------------------------
Palermo
 01/01/21
 Hueso blanco
 Hueso duro
 ..
 05/01/21
 Hueso caracu
 
 02/02/21
 Hueso chico
 Hueso de oro
..
---------------------------------------
Adrogue
 02/02/21
 Hueso chico
 Hueso de oro
 Hueso de colección
 Hueso grande
 ...
 05/04/21
 Hueso negro
...
*/

/*
    Toma de notas
        Ordenar por Zona
        Ordenar por fecha
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DELIM_ZONA "---------------------------------------"


int main(){
    FILE *leer_archivo ("archivos/huesitos.csv", "r");
    return 0;
}