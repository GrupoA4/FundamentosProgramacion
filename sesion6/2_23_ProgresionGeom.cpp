#include <iostream>

using namespace std;

int main (){
	//DECLARACI�N DE VARIABLES.
	int r, a1, k, i, progresion;
	
	//INPUT
	cout << "\nIntroduzca r: ";
	cin >> r;
	cout << "\nIntroduzca a1: ";
	cin >> a1;
	cout << "\nIntroduzca k: ";
	cin >> k;
	
	//C�LCULOS
	for (i=1; i <= k; i++){
		if ( i==1 )
			progresion = a1;
		else
			progresion = progresion * r;	
	}
	
	//OUTPUT
	cout << "\nEl resultado de la progresi�n es: " << progresion;
	system("pause");
}
