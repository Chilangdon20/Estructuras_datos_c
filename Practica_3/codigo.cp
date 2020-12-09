/******************************************************************************

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Se implementan lista circular doble
typedef struct n{
    float c[3]; // c es un arreglo de coordenadas
    struct n *ant, *sig;
}V; // V es para vertice

//protos
FILE* openFile();
V* Lista(FILE*);

int main()
{
    // enlace con el archivo de datos .igs
    FILE* f = openFile();

    /*LA SIGUIENTE FUNCION SE DEDICA A ALMACENAR COORDENADAS
    POR VERTICE EN UNA LISTA CIRCULAR DOBLE*/
    V* lista = Lista(f);

    printf("Hello World");
    fclose(f);

    return 0;
}
//funciones
V* Lista(FILE* f)
{
    //METODOLOGIA LEER LAS ETIQUETAS 110
    int l = 100, i,x;
    V* lista = NULL;
    char str[l],*p = NULL, *sep = ",";

    while (fgets(str,l,f))
    {
        //printf("%s\n",str);
        p = strtok(str,sep);
        if (!strcmp(str,"110"))
        for(x=0;x<2;++x)
            for(i=0;i<3;++i)
            {
                p = strtok(NULL,sep);
                printf("%f\n",atof(p));
            }
    }
     return lista;
}
FILE* openFile()
{
    FILE* a = fopen("Practica_3.igs","rt");
    if(a == NULL)
    {
        printf("Falla de archivo");
        exit(1);
    }
    return a;
}
