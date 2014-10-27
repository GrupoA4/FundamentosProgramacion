/* Programa para listar ventas de una empresa, asociadas a tres parámetros, parando solo cuando el primero de ellos es -1.
*/

#include <iostream>

using namespace std;

int main(){
	enum ID_Sucursal{sucursal1 = 1, sucursal2 = 2, sucursal3 = 3};
	int total_ventas, sucursal, suma_productos1 = 0, suma_productos2 = 0, suma_productos3 = 0, mas_ventas, mejor_sucursal;
	char producto;
	bool sucursal_terminador;
	
	cout << "Introduzca las especificaciones de cada venta separadas por un espacio y separe las ventas con el intro.\n";

	do{
		cin >> sucursal;
		cin >> producto;
		cin >> total_ventas;
		sucursal_terminador = sucursal == -1;
				
		if(sucursal == sucursal1)
			suma_productos1 = suma_productos1 + total_ventas;
		else if(sucursal == sucursal2)
				suma_productos2 = suma_productos2 + total_ventas;
		else if(sucursal == sucursal3)
				suma_productos3 = suma_productos3 + total_ventas;
		
}while(!sucursal_terminador);
	
	if(suma_productos1 >= suma_productos2)
		mas_ventas = suma_productos1;
	else 
		mas_ventas = suma_productos2;
	
	if(mas_ventas < suma_productos3)
		mas_ventas = suma_productos3;
		
	if(mas_ventas == suma_productos1)
		mejor_sucursal = sucursal1;
	else if(mas_ventas == suma_productos2)
			mejor_sucursal = sucursal2;
	else if(mas_ventas == suma_productos3)
			mejor_sucursal = sucursal3;

	cout << "\n\nLa sucursal que más ha vendido ha sido la número " << mejor_sucursal << " con " << mas_ventas << " ventas.\n";
	system("pause");
}
