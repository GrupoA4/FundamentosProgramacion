#include <iostream>
#include <cmath>

using namespace std;

int main (){
	int numero, numero_aux, cifras, i, multiplicador, num_der, num_izq;
	bool desgarrable;
	
	cout << "numero: ";
	cin >> numero;
	cifras = 1;
	numero_aux = numero;
	multiplicador=1;
	i=1;
	
	do{
		numero_aux = numero_aux/10;
		cifras++;
	}while ( (numero_aux/10) > 0 );
	while (i<=cifras && !desgarrable){
		if (i==1){
			num_der = numero % 10;
			num_izq = numero / 10;
		}
		else{
			multiplicador = multiplicador * 10;
			num_der = (multiplicador*(num_izq % 10)) + num_der ;
			num_izq = num_izq / 10;
		}
		desgarrable = ( num_izq + num_der) *  (num_izq + num_der);
		i++;
	}
	if(desgarrable)
		cout << "Es desgarrable.";
	else
		cout << "No es desgarrable.";
	system("pause");
}
