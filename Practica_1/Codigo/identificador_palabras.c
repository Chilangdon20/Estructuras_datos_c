#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>


int main()
{
    setlocale(LC_ALL, "");
    /******************************************************************************
    El siguiente bloque de codigo abre el archivo "texto.txt" en formato lectura "rt"
    lee cada palabra y las escribe en otro archivo en forma de lista.
    *******************************************************************************/
    FILE* pf = NULL, *resultado = NULL; // se declaran 2 punteros a estructura FILE
                                        // pf: archivo fuente. resultado: archivo resulatado

    //declaracion de un puntero a cadena de caracteres
    char p[100] ; //palabra en curso
    int a = 0;

    // se crea elace entre el programa y el archivo que contiene el texto
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
        fscanf(pf,"%s",p); //lee cada cadena y se guarda en p
        /******************************************************************************
        Aqui tenemos cada cadena en un arreglo como potencial palabra

        El siguiente codigo depura una cadena identificando que palabra es.
        *******************************************************************************/
        for(a=0;p[a] != '\0' ;++a)
            if(p[a] > 64 && p[a] < 123)
                fprintf(resultado,"%c",p[a]);
            else
                switch(p[a])
                {
                    case 'á' : fprintf(resultado,"%c",p[a]); break; //a con acento

                    case 'é' : fprintf(resultado,"%c",p[a]); break; //e con acento

                    case 'í' : fprintf(resultado,"%c",p[a]); break; //i con acento

                    case 'ó' : fprintf(resultado,"%c",p[a]); break; //o con acento

                    case 'ú' : fprintf(resultado,"%c",p[a]); break; //u con acento

                    case 'Á' : fprintf(resultado,"%c",p[a]); break; //U con acento

                    case 'É' : fprintf(resultado,"%c",p[a]); break; //A con acento

                    case 'Í' : fprintf(resultado,"%c",p[a]); break; //E con acento

                    case 'Ó' : fprintf(resultado,"%c",p[a]); break; //I con acento

                    case 'Ú' : fprintf(resultado,"%c",p[a]); break; //O con acento

                    case 'ñ' : fprintf(resultado,"%c",p[a]); break; //ene con acento

                    case 'Ñ' : fprintf(resultado,"%c",p[a]); break; //ENE con acento
                }
            //fprintf(resultado,"%d : %c \n",p[a],p[a]); //escribe cada cadena en el archivo de resultado.
        fprintf(resultado,"\n");
    }

    fclose(pf); // se termina con el enlace
    fclose(resultado);
    return(0);
}
