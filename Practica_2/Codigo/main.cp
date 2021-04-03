/* Program: Encontrar las raices de una ecuacion no lineal usando
            el metodo de Newton Raphson Method
   Author: FERNANDO V
  
  
*/


// Incluimos librerias

#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>

// Definición de la ecuación a resolver.

#define    f(x)    pow(x,7)-0.9

// Definimos su derivada  g(x).

#define   g(x)   7*pow(x,6)

using namespace std;

int main()
{
	 float x0, x1, f0, f1, g0, e;
	 int step = 1, N;

	 /* Configuración de precisión y escritura de valores de coma flotante en notación de coma fija. */
     cout<< setprecision(6)<< fixed;

     /* Entradas */
	 cout<<"Ingrese la estimación inicial: ";
	 cin>>x0;
	 cout<<"Ingrese error tolerable:";
	 cin>>e;
	 cout<<"Ingrese la iteración máxima:";
	 cin>>N;

	 /* Implementing Newton Raphson Method */
	 cout<< endl<<"*********************"<< endl;
	 cout<<"Metodo Newton Raphson "<< endl;
	 cout<<"*********************"<< endl;
	 do
	 {
		  g0 = g(x0);
		  f0 = f(x0);
		  if(g0 == 0.0)
		  {
			   cout<<"Error Matematico";
			   exit(0);
		  }


		  x1 = x0 - f0/g0;


		  cout<<"Iteracion-"<< step<<":\t x = "<< setw(10)<< x1<<" & f(x) = "<< setw(10)<< f(x1)<< endl;
		  x0 = x1;

		  step = step+1;

		  if(step > N)
		  {
			   cout<<"No converge.";
			   exit(0);
		  }

		  f1 = f(x1);

	 }while(fabs(f1)>e);

	 cout<< endl<<"Raiz : "<< x1;
	 return 0;
}