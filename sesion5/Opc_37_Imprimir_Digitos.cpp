/* Programa para leer un número entero y que lo devuelva separado por cifras.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int numero, cifra, potencia_de_diez = 10, diez_elevado = pow(10, potencia_de_diez);
	bool hay_cifra_significativa, cifra_no_es_cero;
	
	system("chcp 1252");	
	
	cout << "Introduzca un número: " ;
	cin >> numero;
	
	hay_cifra_significativa = false;
	
	do{
		cifra = numero / diez_elevado;
		cifra_no_es_cero = cifra != 0 ;
		hay_cifra_significativa = hay_cifra_significativa || (cifra_no_es_cero && !hay_cifra_significativa);	//Se vuelve true si ha salido alguna cifra sign.
		
		if(hay_cifra_significativa){
			cout << cifra << " ";
			numero = numero % diez_elevado;
		}
		
		potencia_de_diez--;
		diez_elevado = pow(10, potencia_de_diez);
}while(potencia_de_diez >= 0);
	
	cout << "\n";
	system("pause");
}
