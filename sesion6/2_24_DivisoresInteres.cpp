#include <iostream>

using namespace std;

int main (){
	
	/*---------->EJERCICIO DIVISORES
	---------------------------------------------------------------
	
	//DECLARACIÓN DE VARIABLES.	
	int tope, divisor;
	
	//INPUT USUARIO.
	do{
		cout << "\nIntroduzca un entero positivo: ";
		cin >> tope;
	}while(tope < 0);
	
	//CÁLCULO Y OUTPUT DE DIVISORES.	
	for (divisor = tope; divisor > 0; divisor--){
		if ( tope % divisor == 0)
			cout << "\nEl número " << divisor << " es divisor de " << tope;
	}
	system("pause");
	*/
	
	/*---------->EJERCICIO INTERÉS
	------------------------------------------------------------------
	
	//DECLARACIÓN DE VARIABLES.
	double capital_inicial;
	double capital_total;
	double interes;
	int indice_anio;
	int anios;
	
	//INPUT USUARIO.
	
	cout << "\nIntroduzca el capital inicial: ";
	cin >> capital_inicial;
	cout << "\nIntroduzca el interés (En %): ";
	cin >> interes;
	cout << "\nCuantos años durará la inversión?: ";
	cin >> anios;
	
	//ALGORITMO DE CÁLCULO Y OUTPUT.
	
	interes = 1 + interes / 100;
	capital_total = capital_inicial;
	
	for (indice_anio = 1; indice_anio <= anios; indice_anio++){
		capital_total = capital_total * interes;
		cout << "\nTotal en el año número " << indice_anio << ": " << capital_total;
	}
	system("pause");
	*/
}
