#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // para tolower uso de minusculas
#include <string.h>

// definimos nuestro registro con los datos palabra y ocurrencia
// ESTO ES UN REGISTRO
typedef struct
{
    char* palabra;
    int ocurrencia;//++ocurrencia
}REGISTRO;// TDA

//----------------------------------------------------------------------------------------
//                              PROTOTIPOS DE FUNCIONES

//creacion vinculos rograma-archivo. 'af'c: puntero a file
void VinculoArcivos(FILE** af, FILE** result);

// Depuramos la cadena de caracteres almacenada en el arrelo primario
void depuracion(char* p,char* pa );

// actualizacion de lista
REGISTRO* actualizarLista(REGISTRO* lista, char* pa, int* r);


//----------------------------------------------------------------------------------------
int main()
{
    //electroencefalografista tiene 23 caracteres y es una de las palabras mas largas en nuestro idioma
    char p[30], pa[30]; //declaracion de un buffer primario 'p' y el buffer de palabra pa.


    // renglones: total de registros, letras: longitud de palabra en pa[], n: contador
    int renglones = 0, n = 0 ;


    /***********************************************************************
                Declaracion de la lista de palabras

        lista -> n-registro -> { char *palabra, int ocurrencia}
    *********************************************************************/
    // Se declara la lista:
    //      declaramos un apuntador la estructura REGISTRO, SOBRE EL CUAL HAREMOS LA LISTA
    //      o ARREGLO DE RENGLONES.
    REGISTRO* lista = NULL;// lista + n = el n-esima registro o renglon
                           // (lista + n) -> { char *palabra, int ocurrencia}
                           // acceso a campos.

    // Declaracion de punteros a archivos
    FILE* af = NULL, *resultado = NULL; // se declaran 2 punteros a estructura FILE
                                        // pf: archivo fuente. resultado: archivo resulatado lista de palabras.

    // se crea la conexion programa-archivos
    VinculoArcivos(&af, &resultado);

    /***********************************************************************
                    PROCESAMIENTO DE PALABRAS
    * procedemos a leer el archivo

        * guardamos cada cadena de caracteres que se encuentren en el rango
         [65,122] segun su codigo ASCII y tambien a los que corespondan con
         {'�','�','�','�','�','�','�','�','�','�','�','�'}en un buffer primario p[30].

         Despues depuramos esa cadena quedandonos solo con secuencias de
         caracteres que son capaces de formar palabras en nuestro idioma en otro buffer pa.

            * segun el codigo ASCII 'A' = 65, 'Z'=90, 'a'=97, 'z'=122
              por tanto los caracteres que pueden formar cadenas estan en los intervalos
              [65,90] y [97,122]

                * a los caracteres que estan en el intervalo [65,90]
                  los pasamos por tolower() para obtener minusculas

            *Tambien nos qudamos con los caracteres
             {'�','�','�','�','�','�','�','�','�','�','�','�'}

    *********************************************************************/

    //  * procedemos a leer el archivo
    while(!feof(af)) //la funcion feof recorre todo el archivo hasta EOF
    {
        //lee cada cadena en el archivo de datos y se guarda en p con '\0' al final de cada cadena
        fscanf(af,"%s",p);//llenamos el buffer primario

        /******************************************************************************
        Aqui tenemos cada cadena en un arreglo como potencial palabra

        El siguiente codigo depura una cadena contenida en el buffer primario p[]
        identificando caracteres que correspondan con letras mayusculas y minusculas
        tabien algunos caracteres especiales como

            {'�','�','�','�','�','�','�','�','�','�','�','�'}

        Por otro lado, usaremos conversion de letras mayusculas a minusculas.
        *******************************************************************************/

        // depuracion de cadena contenida en el buffer primario
        depuracion( p, pa );
        //printf("%s\n",pa);
        /**
        Hasta este punto ya tenemos una palabra en el buffer pa[],
        que sera identificada como palabra nueva o como una ocurrencia mas
        de una palabra que ya existe en la lista.

        Despues segun sea el caso se actualizara nuestra lista de palabras diferentes
        contenidas en un texto y su ocurrencia. si es una po=alabra nueva se crea el registro,
        si se trata de una ocurrencia se suma uno a la ocurrencia correspondiente.
        **/

        lista = actualizarLista(lista, pa, &renglones);
        if(lista == NULL){printf("error no se regresa lista"); exit(9);}
    }

    // Escribir lista en archivo nuevo
    printf("anotacion en archivo resultado\n");
    for(n = 0; n < renglones; ++n)
        fprintf(resultado,"%d \t %s \n",(lista + n)->ocurrencia,(lista + n)->palabra);

    //liberecion de  memoria
    for(n = renglones - 1; n >= 0; n--)
    {
       free((lista + n) -> palabra); //libera la n-esima palabra.
       free(lista + n); // libera el n-esimo registro.
    }

    fclose(af);
    fclose(resultado);

    return 0;
}

//----------------------------------------------------------------------------------------

void VinculoArcivos(FILE** af, FILE** result)
{
    // Se crea elace entre el programa y el archivo que contiene el texto
    *af = fopen("https://repl.it/@Estructuras/Practica1#texto.txt","rt");

    // se crea el archivo en el cual se escribiran y leeran los resultados
    *result = fopen("https://repl.it/@Estructuras/Practica1#texto.txt","w+t");

    // verificacion de apertura de archivos
    if(*af == NULL || *result == NULL) // se verifica el enlace
    {
        printf("error al abrir archivo"); // de lo contrario se acaba el programa.
        exit(1);
    }
}

void depuracion(char* p,char* pa )
{
    int n;
    for(n=0;p[n] != '\0' ;++n)
            if(p[n] > 64 && p[n] < 91)//las mayuculas
                pa[n] = tolower(p[n]); // conversion de letras mayusculas a minusculas.
            else
                if(p[n] > 96 && p[n] < 123) //las minusculas
                    pa[n] = p[n];
            else
                switch(p[n]) //caracteres esoeciales
                {   // faltan las dieresis
                    case '�' : pa[n] = p[n]; break; //a con acento

                    case '�' : pa[n] = p[n]; break; //e con acento

                    case '�' : pa[n] = p[n]; break; //i con acento

                    case '�' : pa[n] = p[n]; break; //o con acento

                    case '�' : pa[n] = p[n]; break; //u con acento

                    case '�' : pa[n] = p[n]; break; //U con acento

                    case '�' : pa[n] = p[n]; break; //A con acento

                    case '�' : pa[n] = p[n]; break; //E con acento

                    case '�' : pa[n] = p[n]; break; //I con acento

                    case '�' : pa[n] = p[n]; break; //O con acento

                    case '�' : pa[n] = p[n]; break; //ene con acento

                    case '�' : pa[n] = p[n]; break; //ENE con acento
                }
        //agragamos el caracter de fin de cadena '\0'
        pa[n] = '\0';
}

REGISTRO* actualizarLista(REGISTRO* lista, char* pa, int* r)
{
    //dado que se espera que pa contega una palabra

    printf("funcion actualizar\n");
    // r es el numero de renglones o registros establecidos al momento
    int n, valor=0, letras;

    //Compare la cadena pa[] con (lista + n) -> palabra

    for(n = 0; n < *r; ++n) // si no hay registros no se hace esta operacion
    {
        //comparamos palabra en pa con palabras en lista
        if(0 == strcmp( pa, (lista + n)->palabra ) )//comparamos palabra
        {
            printf("\n nueva ocurrencia\n");
            //valor = 0; //SE AGREGA OCURRENCI
            ++ (lista + n) -> ocurrencia; //se grega una ocurrencia
            return lista;
        }
    }

    // si se trata de una ocurrecia en 'pa' la funcion yta no llegaria a esta parte.
    valor = 1; //pa es una palabra nueva

    if(valor == 1)//se grega un registro
    {
        printf("seagraga un registro\n");
        ++ *r; //un registro mas

        // Asignacion de memoria dinamica a r'renglones' registros en la lista
        lista = (REGISTRO*) realloc(lista,*r * sizeof(REGISTRO)); // sizeof(REGISTRO*n)

        printf("comprobacion de memoria para registro");
        // comprobacion de memoria
        if(lista == NULL) //no se pudo hacer un registros
        {
            printf("error en creacion de registros\n");
            //  liberamos las palabras anteriores free(*(lista + n) -> palabra)
            for(n = *r - 1; n >= 0; n--)
            {
               free((lista + n) -> palabra); //libera la n-esima palabra.
               free(lista + n); // libera el n-esimo registro.
            }

            puts("no hay memoria\n");
            exit(-1);
        }

        letras = strlen(pa) + 1;

        // Anotacion de palabras
        (lista + n) ->palabra = (char*) malloc(sizeof(char)*letras);

        printf("comprobacion de memoria para palabra");
        // comprobacion de memoria
        if((lista + n) ->palabra == NULL)
        {
            printf("error en creacion de palabras\n");
            //  liberamos las palabras anteriores free(*(lista + n) -> palabra)
            for(n = *r - 1; n >= 0; n--)
            {
               free((lista + n) -> palabra); //libera la n-esima palabra.
               free(lista + n); // libera el n-esimo registro.
            }
            puts("no hay memoria\n");
            free(lista);
            exit(-2);
        }

        // llenamos registro con los datos necesarios
        // nueva palabra
        strcpy((lista + n) -> palabra, pa);
        printf("\n cadena almacenada en el registro %d:",n);
        printf("%s\n",(lista + n) -> palabra);
        // ocurrencia minima de 1
        (lista + n) ->ocurrencia = 1;

        printf("termina funcion actualizar\n");
        return lista; //regresa el numero de renglones
    }

}


