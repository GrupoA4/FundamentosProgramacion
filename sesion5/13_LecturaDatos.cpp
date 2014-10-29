/* Programa que lee números hasta que lea el 0, devolviendo el mínimo y el número de datos.
*/

#include <iostream>

using namespace std;

int main(){
	int dato, minimo, contador, terminador = 0;
	bool no_es_cero;
	
	system("chcp 1252");
	
	cout << "Introduzca números:\n";
	cin >> dato;
	
	no_es_cero = dato != terminador;
	
	if(no_es_cero)
		contador = 1;
	else
		contador = 0;
	
	minimo = dato;
	
	while(no_es_cero){
		
		if (dato < minimo)
			minimo = dato;
			
		cin >> dato;
		no_es_cero = dato != terminador;
		
		if (no_es_cero)
			contador++;
	}
	
	cout << "\n\nHa introducido " << contador << " números, y de ellos el menor era " << minimo << "\n";
	
	system("pause");
}
		
