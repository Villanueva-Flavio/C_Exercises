/*

Aladdín le está enseñando a Abu sobre prácticas del lenguaje, y hay un tema en particular que le cuesta
mucho: los prefijos. Es por esto que le hizo un examen sorpresa.
En un archivo se recibirán candidatos a prefijo ( P ) y nombres (N ) donde estos prefijos pueden aparecer o no.
Se pide
Generar un archivo que contenga la cantidad de nombres que coinciden con cada prefijo.
Aclaraciones
• Un prefijo debe tener al menos una letra menos que el nombre.
• Los prefijos solo son válidos si coinciden con el comienzo del nombre.
• La totalidad de prefijos y nombres en el archivo de entrada entran en memoria.
• La salida debe respetar el orden secuencial de aparición de los prefijos en el archivo.
Ejemplo
Recibiendo el archivo:
nombres.txt
P: Jack
N: Jackson
N: Alex
N:Jacques
P:Gonza
P: Alex
N: Alexandra
N: Alexander
N: Jack

Se obtiene:
salida.txt 

1
0
2


• 1: ya que ’Jackson' es el único nombre que cumple con las reglas. Jacques no cumple con las
letras, y Jack tiene la misma longitud que el candidato.
• O: ya que no hay ningún nombre con el prefijo 'Gonza'.
2: ya que 'Alexander' y 'Alexandra' cumplen con las reglas, mientras que 'Alex‘ tiene la misma
longitud que el candidato. 

*/