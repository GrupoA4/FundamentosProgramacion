/* Programa para detectar cu�ntos a�os han de pasar como m�nimo para poder doblar un capital a un inter�s fijo dado.
	Necesita: capital e inter�s.
					capital_inicial, interes.
	Devuelve: numero de a�os.
					numero_anios.
*/

#include <iostream>

using namespace std;

int main(){
	double capital_inicial, capital_total;
	int interes, numero_anios;
	const string mensaje_capital = "Introduzca un capital inicial: ";
	const string mensaje_interes = "Introduzca el inter�s del banco: ";
	const string mensaje_Total_Hasta_Ahora = "Total en el a�o n�mero ";
	
	system("chcp 1252");
	
	cout << mensaje_capital;
	cin >> capital_inicial;
	cout << mensaje_interes;
	cin >> interes;
	
	capital_total = capital_inicial;
	
	while(capital_total < 2*capital_inicial){
		capital_total = capital_total + capital_total * interes/100.0 ;
		numero_anios++;
		cout << mensaje_Total_Hasta_Ahora << numero_anios << " = " << capital_total << "\n";
}
	cout << "\nSe necesitan " << numero_anios << " a�os para alcanzar el doble del capital inicial.\n" ;
	
	system("pause");
}
