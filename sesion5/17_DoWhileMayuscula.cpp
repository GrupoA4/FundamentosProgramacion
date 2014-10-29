/* Programa que pide una mayúscula y devuelve una minúscula, y repite la pregunta hasta que se le dé una.
	Necesita: una mayúscula.
					letra_original.
	Devuelve: la misma letra en minúscula.
					letra_convertida.
*/

#include <iostream>

using namespace std;

int main(){
	char letra_original, letra_convertida;
	const int DIFERENCIA_MAY_MIN = 'a' - 'A';
	bool es_mayuscula;
	const string mensaje_Introduzca = "Introduzca a continuación una letra mayúscula: " ;
	const string mensaje_minuscula = "Su letra convertida en minúscula es " ;
	
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
