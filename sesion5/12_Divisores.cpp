/* Programa que devuelve los divisores de un n�mero dado.
	Necesita: un n�mero.
					tope.
	Devuelve: todos sus divisores.
					divisor.
*/
#include <iostream>

using namespace std;

int main(){
	int tope, divisor = 1;
	bool es_divisor;
	const string mensaje_introduzca_tope = "Introduzca el n�mero del que quiera hallar sus divisores: " ;
	
	
	system("chcp 1252");
	
	do{
	cout << mensaje_introduzca_tope;
	cin >> tope;
}while(tope<=0);
	
	cout << "Los divisores del n�mero dado son:\n";
	
	while(tope >= divisor){
		es_divisor = tope % divisor == 0;
		if(es_divisor)
			cout << divisor << " ";
		divisor++;
	}
	
	cout << "\n";
	system("pause");
}
