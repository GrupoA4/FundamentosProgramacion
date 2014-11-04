#include <iostream>

using namespace std;

int main (){
	//DECLARACIÓN DE VARIABLES
	int entrada, numero, repeticiones;
	
	//INPUT
	cout << "\nIntroduzca números naturales: ";
	cin >> entrada;
	
	//ALGORITMO RLE Y OUTPUT
	while (entrada >= 0){
		repeticiones = 1;
		numero = entrada;
		while ( entrada >= 0 && entrada == numero){
			cin >> entrada;
			if (entrada == numero)
				repeticiones++;
		}
		cout << repeticiones << " " << numero << " ";
	}
	system("pause");
}
