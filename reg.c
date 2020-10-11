/******************************************************************************
Objetivo: hacer un arreglo apuntadores a cadenas de caracteres que almacene
palabras y su ocurrencia.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//se declara un estructura que contiene una palabra nueva y su numero de ocurrencias
typedef struct
{
    char* palabra;
    int ocurrencia;
}REGISTRO;

int main()
{
    int renglon = 0, columnas = 0, n=0;
    char p[20]; //BUFER

    // se declara la lista:
    //declaramos un apuntador la estructura REGISTRO, SOBRE EL CUAL HAREMOS LA LISTA
    REGISTRO* lista = NULL;// lista + n = el n-esima registro
                           // *(lista + n) -> { char *palabra, int ocurrencia}

    // ESQUEMA DE LA ESTRUCTURA DE DATOS
    // lista -> n-registro -> { char *palabra, int ocurrencia}

    // Asignacion de memoria dinamica a un nuevo registro en la lista
    lista = (REGISTRO*) realloc(lista,sizeof(REGISTRO));
    if(lista == NULL)
    {   //no se pudo hacer un registro
        //liberamos las palabras anteriores free(*(lista + n) -> palabra)
        // despues los registros free(lista + n)
        //simultaneamete en ese orden las veces que sean necesarios
        puts("no hay memoria\n");
        exit(-1);
    }

    //----------------------------------------------------------------------------
    printf("Escribe tu nombre: ");
    gets(p);
    columnas = strlen(p)+1; // indicamos el tamano de la nueva palabra mas uno para '\0'
    //----------------------------------------------------------------------------

    //anotacion de palabras
    (lista + n) ->palabra = (char*) malloc(sizeof(char)*columnas);
    if((lista + n) ->palabra == NULL)
    {   //no se puede escribir la nueva palabra
        //liberamos las palabras anteriores free(*(lista + n) -> palabra)
        // despues los registros free(lista + n)
        //simultaneamete en ese orden las veces que sean necesarios
        puts("no hay memoria\n");
        free(lista);
        exit(-2);
    }

    strcpy(lista->palabra,p);
    printf("\n tu nombre es: %s",lista->palabra);

    free(lista->palabra);
    free(lista);

    return 0;
}
