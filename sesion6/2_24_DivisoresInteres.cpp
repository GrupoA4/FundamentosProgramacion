#include <iostream>

using namespace std;

int main (){
	
	/*---------->EJERCICIO DIVISORES
	---------------------------------------------------------------
	
	//DECLARACI�N DE VARIABLES.	
	int tope, divisor;
	
	//INPUT USUARIO.
	do{
		cout << "\nIntroduzca un entero positivo: ";
		cin >> tope;
	}while(tope < 0);
	
	//C�LCULO Y OUTPUT DE DIVISORES.	
	for (divisor = tope; divisor > 0; divisor--){
		if ( tope % divisor == 0)
			cout << "\nEl n�mero " << divisor << " es divisor de " << tope;
	}
	system("pause");
	*/
	
	/*---------->EJERCICIO INTER�S
	------------------------------------------------------------------
	
	//DECLARACI�N DE VARIABLES.
	double capital_inicial;
	double capital_total;
	double interes;
	int indice_anio;
	int anios;
	
	//INPUT USUARIO.
	
	cout << "\nIntroduzca el capital inicial: ";
	cin >> capital_inicial;
	cout << "\nIntroduzca el inter�s (En %): ";
	cin >> interes;
	cout << "\nCuantos a�os durar� la inversi�n?: ";
	cin >> anios;
	
	//ALGORITMO DE C�LCULO Y OUTPUT.
	
	interes = 1 + interes / 100;
	capital_total = capital_inicial;
	
	for (indice_anio = 1; indice_anio <= anios; indice_anio++){
		capital_total = capital_total * interes;
		cout << "\nTotal en el a�o n�mero " << indice_anio << ": " << capital_total;
	}
	system("pause");
	*/
}
