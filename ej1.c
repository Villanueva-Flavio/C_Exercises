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
* Eddy decidio elegir tentre los clavos que se encuentran en cualquier posicion de su vector
* Cada uno de ellos, eligirá el clavo mas largo
* De esos 3 clavos, el elegido para usar como piercing de tablón será el menos doblado.

1. Crear una funcion que muestre por pantalla el nombre del Rey del barrio y la posicion del clavo ganador

*/

