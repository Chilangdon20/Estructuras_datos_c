/******************************************************************************

Practica 2: sistema automatico de negociacion

OBJETIVO: Que el alumno diseñe un algoritmo para comprar y vender acciones
          bursátiles de forma automática.

Problema:

    El programa debe ser capaz de leer el archivo de texto donde aparece
    una lista de precios de la acción de Alphabet Inc durante el último año
    (al momento de la apertura, un precio en cada renglón) y decidir en qué
    momento comprarlo y en qué momento venderlo. Para esto se debe
    definir los criterios que harán que el programa compre y venda una
    acción. El programa debe tomar en cuenta el capital necesario para
    poder comprar la acción cuando lo requiera. Para cada operación
    mostrar en la pantalla la ganancia o pérdida de dicha operación y el
    acumulado desde el principio del archivo.

ALGORITMO

DATOS
    'p' arreglo de precios de una accion p[i] = precio actual de la accion
    's' saldo (inicial s = 2000)
    'v' valor de la accion (inicial v = 0)
    'u' umbral inicial para comprar


---Algoritmo---
inicio estrategia
    si p es menor que u:
        comprar accion:
            s -= p[i]
            v = p[i]
    fin si
    mientras no se acaben los datos:
        actualizar lista de precios p.
        si s+p[i] > s+p[i-1]:
            vender accion // accion va a la alza
        fin si
        sino
            si s-p[i] > s-p[i-1] :
                comprar accion: // accion a la baja
                    s -= p[i]
                    v = p[i]
            fin si
        fin sino
    fin mientras
fin estrategia


*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define TAM 10
// falta funcion que agranda el arreglo de precios
typedef struct{
    float *p;
    int tam;
    int cap;
    int v; //v=0 no hay accion, v=1 si hay accion
    float sal;
}precios;

precios lista = {NULL,TAM,0,0,2000};

//prototipos
void compra();
void vende();
FILE* enlaceArchivo();
FILE* primerCompra(FILE*);
void ExpandeArreglo();
FILE* estrategia(FILE*);

int main()
{
    // acceder al archivo FUNCIONA
    FILE* datos = enlaceArchivo();

    // se crea la primer compra y se regresa el arreglo de precios
    datos = primerCompra(datos);

    //empieza estrategia de trading
    datos = estrategia(datos);


    fclose(datos);
    //free(lista.p);
    printf("Hello World");

    return 0;
}
FILE* estrategia(FILE* datos)
{
    printf("\nEstrategia en marcha\n");
    //iniciamos el contador en un espacio libre
    int i = 1+lista.cap;
    while(!feof(datos)) //la funcion feof recorre todo el archivo hasta EOF
    {
        // revisar espacio de almacenamiento
        if(lista.cap == lista.tam)
                ExpandeArreglo();

        // actualizar lista de precios
        fscanf(datos, "%f",lista.p+i);
        lista.cap = i;
        printf("precio de la accion dia %d: $%.2f\n",i+1,lista.p[i]);
        //evaluar accion y tomar una decision
        switch(lista.v)
        {
            case 0://analiza compra

                if(lista.sal > lista.p[i])
                    if(lista.sal-lista.p[i] < lista.sal-lista.p[i-1]) //acion a la baja
                        compra();
                break;

            case 1://analiza venta

                if(lista.sal+lista.p[i] > lista.sal+lista.p[i-1]) // accion a la alza
                    vende();
                break;
        }

        ++i;
    }
    return datos;
}
void ExpandeArreglo()
{
    // se asigna el nuevo tamaño
    (lista.tam) *= 2;
    //contador
    int i = 0;
    //se cra arreglo auxiliar con el nuevo tamaño
    float *a = (float*)malloc((lista.tam)*sizeof(float));
    if(a == NULL)
    {
        printf("\nSe termino el espacio.");
        exit(-1);
    }
    //se mudan los datos
    for(;i<=lista.cap;++i)
        a[i] = lista.p[i];
    free(lista.p);
    // añadimos el arreglo con mas espacio a la lista
    lista.p = a;
    a = NULL;
}
FILE* primerCompra(FILE* datos)
{
    printf("Primera compra\n");
    float u;//umbral
    int i=0;
    // SE CREA EL ARREGLO DE PRECIOS
    lista.p = (float*)malloc(sizeof(float)*lista.tam);
    if(lista.p == NULL)exit(-1);

    //se prepara la primer comprar
        printf("Tiene un saldo de: %.2f\nIndique el precio maximo para comprar: ",lista.sal);
        do
        {
            scanf("%f",&u);
            if(u>=lista.sal) printf("No tienes $%.2f, indica otro umbral: ",lista.sal);
        }while(u>=lista.sal);


        while(!feof(datos)) //la funcion feof recorre todo el archivo hasta EOF
        {
            if(lista.cap == lista.tam)
                ExpandeArreglo();
            fscanf(datos, "%f",lista.p+i);
            lista.cap = i;
            printf("precio de la accion dia %d: $%.2f\n",i+1,lista.p[i]);
            if(lista.p[i] < u)
            {
                compra();
                break;
            }
            ++i;
        }
    //fin primer compra

    if(lista.v==0)
    {
        printf("\nNo hay ninguna accion con valor menor a $%.2f.",u);
        exit(2);
    }
    return datos;
}
FILE* enlaceArchivo()
{
    FILE* p = fopen("GOOGL.txt", "rt");
    if(p == NULL) // se verifica el enlace
    {
        printf("error al abrir archivo"); // de lo contrario se acaba el programa.
        exit(1);
    }
    return p;
}
void compra()
{
    printf("\nCompra accion\n");
    int i = lista.cap;
    lista.sal -= lista.p[i]; //pagas
    lista.v = 1;
    printf("valor de la accion: $%.2f\n",lista.p[i]);
    printf("saldo actual: %.2f\n\n",lista.sal);
}
void vende()
{
    printf("\nvende accion ");
    int i = lista.cap;
    lista.sal += lista.p[i]; //cobras
    lista.v = 0;
    printf("por: $%.2f\n",lista.p[i]);
    printf("saldo actual: %.2f\n\n",lista.sal);
}


