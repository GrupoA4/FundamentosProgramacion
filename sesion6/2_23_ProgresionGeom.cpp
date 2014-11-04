#include <iostream>

using namespace std;

int main (){
	//DECLARACIÓN DE VARIABLES.
	int r, a1, k, i, progresion;
	
	//INPUT
	cout << "\nIntroduzca r: ";
	cin >> r;
	cout << "\nIntroduzca a1: ";
	cin >> a1;
	cout << "\nIntroduzca k: ";
	cin >> k;
	
	//CÁLCULOS
	for (i=1; i <= k; i++){
		if ( i==1 )
			progresion = a1;
		else
			progresion = progresion * r;	
	}
	
	//OUTPUT
	cout << "\nEl resultado de la progresión es: " << progresion;
	system("pause");
}
