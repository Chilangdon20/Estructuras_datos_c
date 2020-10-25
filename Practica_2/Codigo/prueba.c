
#include <stdio.h> 

/* Defino una estructura llamado datos , que contiene los dos datos que nos interesan
 comprar y vender , donde va a almacenar los dias rspectios en los que se deben de comprar.
 */
struct Datos { 
    int comprar; 
    int vender;
}; 

/* 

Esta funcion toma como argumento el array de precios y m , 
donde m es el tamaño del array de los precios

*/
void comprarVender(int precio[], int m) 
{ 
	/*Verificamos que los precios se den por almenos 2 dias , entonces retornamos */ 
	if (m == 1) return; 

	int contador = 0; 

	/*Creamos un array de nuestra estructura de tipo Datos 
	Su tamaño se establece asi ya que ese es el tamaño maximo que se requiere */ 
	Datos sol[m /2 + 1]; 

	
	int j = 0; 
	
	// Ejecutamos un loop m-1 , esto significa que los elementos aun deben procesarse en el array
	while (j < m - 1) { 
	    
	    // Con este while tratamos de encontrar un local minimo , con la condicion de que el precio del siguiente elemento sea menor que el actual
	    // hasta que se cumpla esa condicion seguimos el incremento de j
	    
	    while ((j < m - 1) && (precio[j + 1] <= precio[j])) 
	        
	        j++; 

		/*Aqui Verificamos si j es igual a m-1 
		por que si es el caso , significa que no hay mas soluciones posibles y por lotanto hacemos un break
		*/ 
		if (j == m - 1) 
		    
		    break; 

		/*De lo contrario almacenamos el indice de nuestros minimos locales */ 
		sol[contador].comprar = j++; 

		/*Este while sirve para hallar los maximos locales
		indicando que el precio de la accion actual sea mayor ue la anterior,
		salimos del ciclo cuando la accion anterior es mayor que la accion actual*/
		
		while ((j < m) && (precio[j] >= precio[j - 1])) j++; 

		/* Guardamos el indice de nuestro maximo , como j-1*/
		sol[contador].vender = j - 1;
		contador++; 
	} 

	/* Ahora tenemos el valor final de nuestra variable contador
	Con el if indicamos si nuestro contador es igual a 0 indicamos que no existe un dia conveniente
	para comprar acciones*/
	
	
	if (contador == 0) printf("No te conviene comprar ya que no hay dias para generara ganancias"); 
	
	/*Imprimimos los dias en los que podemos obtener ganancias comprando y vendindo nuestras
	acciones*/
	else { for (int j = 0; j < contador; j++) printf("Compra el dia: %dt & vende el dia: %dn", sol[j].comprar, sol[j].vender);} 

	return; 
} 

int main() 
{ 
	
	int precio[] = { 1183
,1159.45
,1185.17
,1193.8
,1195.82
,1195.35
,1191.83
,1180.79
,1168.43
,1176.07
,1174.35
,1180
,1199.995
,1186.43
,1157.8
,1165.52
,1172.97
,1203
,1217.63
,1224.87
,1227
,1242.5
,1228
,1138.95
,1132.62
,1143.45
,1135.47
,1149.32
,1142
,1150.92
,1146.73
,1145.34
,1142.93
,1146.16
,1132.32
,1110.32
,1125.87
,1119.37
,1118.5
,1104.83
,1101.04
,1077.23
,1086.75
,1091
,1115.08
,1120
,1109.86
,1121.7
,1107.24
,1111.5
,1089.1
,1089.74
,1084.71
,1079.95
,1096.99
,1077
,1054.28
,1046.21
,1055
,1044.49
,1066.93
,1105.64
,1120.15
,1132.7
,1141.48
,1152
,1146.07
,1151.25
,1154.48
,1153
,1175.83
,1084.02
,1107.3
,1083.49
,1055.02
,1072.53
,1089
,1091.4
,1068.2
,1020.01
,1096.54
,1048.33
,1080.3
,1115
,1091.29
,1112.51
,1103.71
,1130
,1140
,1113.48
,1118
,1119.64
,1079.04
,1136.4
,1151.31
,1160
,1176
,1205.03
,1212
,1206.67
,1213
,1204.09
,1200
,1193.69
,1184.25
,1159.41
,1194.92
,1180.67
,1168.96
,1162.66
,1177.77
,1188
,1179.7
,1182
,1171.1
,1184.2
,1172
,1198.57
,1209.22
,1222.52
,1252.21
,1263.4
,1255
,1255.9
,1244.14}; 
	
	// calculo de len de la matriz dividiendo el tamaño de la matriz entre el tamaño del primer elemento
	int m = sizeof(precio) / sizeof(precio[0]); 

	// Llamado de funcion
	comprarVender(precio, m); 

	return 0; 
} 