#include <iostream>

using namespace std;

int main (){
	int indice;
	double suma, signatura;
	
	suma=0.0;
	signatura=1.0;
	for (indice = 1; indice <= 100; indice++){
		signatura = signatura * (-1);
		suma = suma + ( signatura * (indice * indice - 1) / ( 2 * indice )  );
	}
	
	cout << "El resultado es: " << suma;
	system("pause");
}
