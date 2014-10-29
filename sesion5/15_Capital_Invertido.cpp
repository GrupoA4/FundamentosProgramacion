/* Programa para calcular el capital total que se produce al invertir un n�mero de a�os N en un banco de un inter�s fijo dado.
	Necesita: capital a invertir, numero de a�os e inter�s.
					capital_a_invertir, numero_a�os, interes.
	Devuelve: capital total.
					capital_total.
*/

#include <iostream>

using namespace std;

int main(){
	double capital_inicial, capital_total;
	int interes, numero_anios, contador_repeticiones = 0;
	const string mensaje_capital = "Introduzca un capital inicial: ";
	const string mensaje_interes = "Introduzca el inter�s del banco: ";
	const string mensaje_numero_anios = "Introduzca el n�mero de a�os que mantendr� el capital en el banco: ";
	const string mensaje_Total_Hasta_Ahora = "Total en el a�o n�mero ";
	
	system("chcp 1252");
	
	cout << mensaje_capital;
	cin >> capital_inicial;
	cout << mensaje_interes;
	cin >> interes;
	cout << mensaje_numero_anios;
	cin >> numero_anios;
	
	capital_total = capital_inicial;
	
	while(numero_anios > contador_repeticiones){
		capital_total = capital_total + capital_total * interes/100.0 ;
		contador_repeticiones++;
		cout << mensaje_Total_Hasta_Ahora << contador_repeticiones << " = " << capital_total << "\n";
}
	
	system("pause");
}
