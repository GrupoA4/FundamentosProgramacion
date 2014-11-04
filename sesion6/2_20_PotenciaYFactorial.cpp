#include <iostream>

using namespace std;

int main (){
	//DECLARACIÓN DE VARIABLES	
	double x, potencia;
	int n, factorial, i;
	
	//INPUT
	cout << "\nIntroduzca X: ";
	cin >> x;
	cout << "\nIntroduzca N: ";
	cin >> n;
	
	//CÁLCULOS
	factorial = 1;
	potencia = 1;
	for (i=1; i<=n ; i++)
		factorial = factorial * i;
	for (i=n; i>0 ; i--)
		potencia = potencia * x;
	
	//OUTPUT
	cout << "\nEl factorial es: " << factorial << " y la potencia es: " << potencia;
	system("pause");
}
