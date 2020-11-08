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
    


inicio estrategia
si p <= u:
    compra accion
        s -= p[i]
        v = p[i]
mientras no se acaben los datos
    actualizar lista de precios p
    si s+p[i] > s+p[i-1]: vende accion // accion va a la alza
    sino 
        si s-p[i] > s-p[i-1] : compra accion // accion a la baja
        

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define TAM 10
// falta funcion que agranda el arreglo de precios

//prototipos
int compra(float*,float* ,int);
int vende(float*,float* ,int);


int main()
{
    //DATOS
    int tam = TAM, i=0, v = 0;
    float *p = NULL;
    float s = 2000 , u;
    
    // acceder al archivo FUNCIONA
    FILE* datos = NULL;
    datos = fopen("precios", "rt");
    if(datos == NULL) // se verifica el enlace
    {
        printf("error al abrir archivo"); // de lo contrario se acaba el programa.
        exit(1);
    }
    
    
    // SE CREA EL ARREGLO DE PRECIOS
    p = (float*)malloc(sizeof(float)*TAM);
    if(p == NULL)return -1;
    
    // if(i== TAM) expande_arreglo(p,tam);
    
    //se prepara la primer comprar
        printf("Tiene un saldo de: %.2f\n indique el precio maximo para comprar: ",s);
        do
        {
            scanf("%f",&u);
            if(u>=s) printf("No tienes $%.2f, indica otro umbral: ",s);
        }while(u>=s);
        
        
        while(!feof(datos)) //la funcion feof recorre todo el archivo hasta EOF
        {
            if(i == TAM) break; //EXPANDE ARREGLO
                // if(i== TAM) expande_arreglo(p,tam);
            fscanf(datos, "%f",p+i);
            printf("precio de la accion dia %d: $%.2f\n",i+1,p[i]);
            if(p[i] < u)  
            {
                v = compra(&s, p, i);
                ++i;
                break;
            }
            ++i;
        }
    //fin primer compra
    
    if(v==0)
    {
        printf("\nNo hay ninguna accion con valor menor a $%.2f.",u);
        return 2;
    }
    
    //empieza estrategia
    while(!feof(datos)) //la funcion feof recorre todo el archivo hasta EOF
    {
        fscanf(datos, "%f",p+i);
        printf("precio de la accion dia %d: $%.2f\n",i+1,p[i]);
        switch(v)
        {
            case 0://analiza compra
            
                if(s > p[i])
                    if(s-p[i] < s-p[i-1]) //acion a la baja
                        v = compra(&s, p, i);
                break;
                        
            case 1://analiza venta
            
                if(s+p[i] > s+p[i-1]) // accion a la alza
                    v = vende(&s, p, i);
                break;
        }
        
        ++i;
    }
    
    free(p);
    fclose(datos);
    printf("Hello World");

    return 0;
}
int compra(float* s,float* p,int i)
{
    printf("\nCompra accion\n");
    *s -= p[i]; //pagas
    printf("valor de la accion: $%.2f\n",p[i]);
    printf("saldo actual: %.2f\n\n",*s);
    return 1;
}
int vende(float* s,float* p ,int i)
{
    printf("\nvende accion ");
    *s += p[i]; //cobras
    //*v = 0; //entregas
    printf("por: $%.2f\n",p[i]);
    printf("saldo actual: %.2f\n\n",*s);
    return 0;
}


