/* Programa que pide una may�scula y devuelve una min�scula, y repite la pregunta hasta que se le d� una.
	Necesita: una may�scula.
					letra_original.
	Devuelve: la misma letra en min�scula.
					letra_convertida.
*/

#include <iostream>

using namespace std;

int main(){
	char letra_original, letra_convertida;
	const int DIFERENCIA_MAY_MIN = 'a' - 'A';
	bool es_mayuscula;
	const string mensaje_Introduzca = "Introduzca a continuaci�n una letra may�scula: " ;
	const string mensaje_minuscula = "Su letra convertida en min�scula es " ;
	
	system("chcp 1252");
	
	do{
	cout << mensaje_Introduzca;
	cin >> letra_original;
	es_mayuscula = letra_original >= 'A' && letra_original <= 'Z';
}while(!es_mayuscula);
	
	letra_convertida = letra_original + DIFERENCIA_MAY_MIN;
	
	cout << mensaje_minuscula << letra_convertida << "\n";
	system("pause");
}
