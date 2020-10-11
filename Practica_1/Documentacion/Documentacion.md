# DOCUMENTACION


## Objetivo:

Realizar una aplicacion que lea un texto de un archivo.txt, cuente la
ocurrencia de cada palabara en el texto y por ultimo imprima en otro archivo.txt
una lista con las palabras y su ocurrencia en el texto en forma ascendente.


# Metodologia: 

Se usara la siguiente estructura de procesamiento de datos.

 ESQUEMA DE LA ESTRUCTURA DE DATOS (lista de palabras y su ocurrencia):
    
  * archivo (fuente) -> cadenas -> palabras -> lista        
  * lista -> n-registro -> { char *palabra, int ocurrencia} 
  * lista -> archivo (resultado)                            

El cual describe un proceso de acumulacion de palabras diferentes (contenidas
en el texto fuente),en una lista, en donde tambien se almacena el numero
de ocurrencias de esa palabra en el texto,
finalmete se almacenan los datos generados en otro archivo de texto.
Procedimiento:

 1) crear conexion programa-archivo con los arvivos fuente y resultado.

 2) Declaracion de la estructura de datos.
 
   Dado que nuestro objetivo es optener una lista de las palabras en ese texto y
   su ocurrencia en el mismo, pensamos en una estructura de datos que cumple con tales
   requerimientos:

 **La lista de palabras distintas y su ocurrencia en un texto esta soportada en C por
    la siguiente estructura de datos
    lista : Arrglo de estructuras.**

 **Cada estructura consiste en un registo de los siguientes datos:**
    * palabra     (puntero a cadena de caracteres).
    * Ocurrencia  (valor entero que inicia en 1 ).

 3) Extraemos del texto fuente cadenas de caracteres con ayuda de la funcion fscanf()
   y las almacenamos en un arreglo de caracteres primario que no precisamente formen
   palabras en nuestro idioma.
 4) Depuramos la cadena de caracteres almacenada en el arrelo primario, de aquellos
   caracteres que no son capaces de formar una palabra, en otras palabras; nos quedamos
   unicamente con los caracteres que corresponden a letras del alfabeto latino,
   vocales con acentos y dieresis tambien estan contenidos en la categoria de
   caracteres capaces de formar palabras.Tales caracteres se almacenan en un nuevo arreglo
   de caracteres denominado 'pa' (palabras).
 5) Indicamos si la palabra contenia en el arreglo 'pa' es una palabra diferente o es una
   ocurrencia de alguna palabra ya existente en nuestra lista de palabras direrentes y su
   ocurrencia en un texto.
   Para dicernir hacemos una comparacion entre la cadena contenida en 'pa' y las palabras
   almacenadas en todos los registros de nuestra lista. strcmo(pa,palabra)
   si es una nueva palabra: creamos un nuevo registro con los siguientes datos
                            strcpy(palabra, pa);
                            ocurrencia  = 1;
    si es una ocurrencia : se se le suma 1 a la ocurrencia de la palabra con la que coincide la cadena cointenida en 'pa'


 6) repetimos los pasos 3), 4), 5), hasta encontrarnos con el final del archivo.

 7) ordenamos las palabras optenisas segun su numero de ocurrencias.

  8) imprimimos en otro archivo la lista ordenada.
