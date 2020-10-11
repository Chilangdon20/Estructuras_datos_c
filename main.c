/******************************************************************************
Autor:Alexis Terecro
Objetivo:
Realizar una aplicacion que lea un texto de un archivo .txt, cuente la
ocurrencia de cada palabara en el texto y por ultimo imprima en otro archivo
una lista con las palabras y su ocurrencia en el texto en forma ascendente.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //El siguiente bloque de codigo abre el archivo "texto.txt" en formato lectura "rt"
    FILE* pf = NULL, *resultado = NULL; // se declaran 2 punteros a estructura FILE

    //declaracion de un puntero a cadena de caracteres
    char p[100] ;

    // se crea enlace entre el programa y el archivo que contiene el texto
    pf = fopen("C:\\Users\\Lolita\\Desktop\\UANM2021_1\\Estrucuctura_datos\\sesion_10_02_2020\\texto.txt","rt");
    // se crea el archivo en el cual se escribiran y leeran los resultados
    resultado = fopen("C:\\Users\\Lolita\\Desktop\\UANM2021_1\\Estrucuctura_datos\\sesion_10_02_2020\\resultado.txt","w+t");
    if(pf == NULL || resultado == NULL) // se verifica el enlace
    {
        printf("error al abrir archivo"); // de lo contrario se acaba el programa.
        exit(1);
    }

    // procedemos a leer el archivo
    //procedemos a contar las palabras dentro del archivo a leer
    while(!feof(pf)) //la funcion feof recorre todo el archivo hasta EOF
    {
        fscanf(pf,"%s",p); //lee cada cadena
        fprintf(resultado,"%s \n",p); //escribe cada cadena en el archivo de resultado.
    }

    fclose(pf); // se termina con el enlace
    fclose(resultado);
    return(0);
}