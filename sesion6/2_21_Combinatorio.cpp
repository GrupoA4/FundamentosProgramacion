#include <iostream>

using namespace std;

int main (){
	//DECLARACIÓN DE VARIABLES
	int n, m, n_menos_m, indice, n_factorial, m_factorial, n_menos_m_factorial;
	double numero_combinatorio;
	
	//INPUT
	cout << "\nIntroduzca n: ";
	cin >> n;
	cout << "\nIntroduzca m: ";
	cin >> m;
	
	//ALGORITMO
	n_menos_m = n - m;
	n_factorial = 1;
	m_factorial = 1;
	n_menos_m_factorial = 1;
	
	for (indice = 1; indice <= n; indice++)
		n_factorial = n_factorial * indice;
	for (indice = 1; indice <= m; indice++)
		m_factorial = m_factorial * indice;
	for (indice = 1; indice <= n_menos_m; indice++)
		n_menos_m_factorial = n_menos_m_factorial * indice;
	numero_combinatorio = n_factorial / ( m_factorial * n_menos_m_factorial);
	
	//OUTPUT
	cout << "\nEl número combinatorio es: " << numero_combinatorio;
	system("pause");
}
