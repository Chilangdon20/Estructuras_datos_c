#include <stdio.h>
#include<stdlib.h>
#include <ctime>
//lista simple
struct n{
    struct n *sig;
    char art[20];
};

// para que sirve esta parte
typedef struct n pila;

// la linea 14 no entiendo para que funciona
int revisarPila(pila*);
// ¿este es el llamado de funcion?
pila* push(pila*);//push front
pila* sacar(pila*);

int main()
{   


  
    // declaracion de variables
    pila *p = NULL;
    time_t first, second;
    first = time(NULL); // empieza a contar el tiempo
    int seleccion;
    do
    {   printf("\n _______________________________");
        printf("\n|        𝑀𝐸𝑁𝑈                 |");
        printf("\n|_______________________________|");
        printf("\n|                               |");
        printf("\n|0- Terminar                    |");
        printf("\n|1- Agregar objeto              |");
        printf("\n|2- Eliminar ultimo objeto      |");
        printf("\n|_______________________________|\n");
        printf("\n ↪ Seleccion:");
        scanf("%d",&seleccion);
        //inica conteo tiempo
        
        switch(seleccion) 
        {
          case 1: // meter
            printf("\n↪Añadir\n");
            p = push(p);
            break;
          case 2: // sacar
            printf("\n↪Eliminar\n");
            p = sacar(p);
            break;
        }
    }while(seleccion != 0);
    //borrar pila si termino el programa
    while(p!=NULL) p=sacar(p);
    second = time(NULL);
    printf("\n↪Tiempo demorado en vaciar pila: %f segundos",difftime(second, first));
  
    return 0;
}
//funciones

// popfront
pila* sacar(pila* p)
{   
    
    // ¿En caso de que nuestro elemento sea cero retornar p?
    if(revisarPila(p) == 0) return p;
    printf("\n↪Se saca: %s\n",(p->art));
    
    //funcionamiento  popfront
    pila *aux = p;
    p = p->sig;
    free(aux);
    return p;
}
pila* push(pila* p)
{
    pila *aux = (pila *)malloc(sizeof(pila));
    //pedir cadena de articulo
    printf("\n↪Digite nombre del articulo: ");
    scanf ("%s",aux->art);
    //append
    aux->sig = p;
    // esta parte no la entiendo p= aux
    p = aux;
    aux =NULL;
    return p;
}

int revisarPila(pila* p)
{   
    
    // esta parte tampoco la entiendo
    if(p != NULL) return 1;
    printf("\n↪Pila vacia\n");
    return 0;
}