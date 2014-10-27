/* Programa para devolver una renta neta a partir de la renta bruta y ciertos datos fiscales.
*/

#include <iostream>

using namespace std;

int main(){
	char respuesta_autonomo, respuesta_pensionista, respuesta_estado_civil;
	bool es_autonomo, es_pensionista, es_soltero, renta_baja;
	double renta_bruta, renta_neta, retencion_inicial, retencion;
	const double RETENCION_PENSIONISTAS = 1, RETENCION_OTROS = 2, RETENCION_AUTONOMOS = 3, RETENCION_RENTA_BAJA = 6, RETENCION_CASADOS = 8;
	const double RETENCION_SOLTEROS = 10;
	double indice_variacion;
	const string mensaje_autonomo = "¿Es usted autónomo?{S/N} ";
	const string mensaje_pensionista = "¿Es usted pensionista?{S/N} ";
	const string mensaje_estado_civil = "¿Cuál es su estado civil?{Responda S si es soltero, C si casado} ";
	const string mensaje_renta_bruta = "¿Cuál es el valor de su renta bruta? ";
	const string mensaje_retencion_inicial = "¿Cuál es el valor de su retención inicial? ";
	const string mensaje_final = "\n\nSu renta neta es de un valor de ";
	
	system("chcp 1252");
	
	do{
		cout << mensaje_autonomo;
		cin >> respuesta_autonomo;
		respuesta_autonomo = toupper(respuesta_autonomo);
	}while(respuesta_autonomo != 'S' && respuesta_autonomo != 'N');
	
	do{
		cout << mensaje_pensionista;
		cin >> respuesta_pensionista;
		respuesta_pensionista = toupper(respuesta_pensionista);
	}while(respuesta_pensionista != 'S' && respuesta_pensionista != 'N');

	do{
		cout << mensaje_estado_civil;
		cin >> respuesta_estado_civil;
		respuesta_estado_civil = toupper(respuesta_estado_civil);
	}while(respuesta_estado_civil != 'S' && respuesta_estado_civil != 'C');
	
	cout << mensaje_renta_bruta;
	cin >> renta_bruta;
	cout << mensaje_retencion_inicial;
	cin >> retencion_inicial;
	
	es_autonomo = respuesta_autonomo=='S';
	es_pensionista = respuesta_pensionista=='S';
	es_soltero = respuesta_estado_civil=='S';
	renta_baja = renta_bruta < 20000;
	
	if(es_autonomo)
		retencion = retencion_inicial - retencion_inicial * RETENCION_AUTONOMOS/100.0;
	else
		if(es_pensionista)
			retencion = retencion_inicial + retencion_inicial * RETENCION_PENSIONISTAS/100.0;
		else{
			retencion = retencion_inicial + retencion_inicial * RETENCION_OTROS/100.0;
			if(renta_baja)
				retencion = retencion + retencion * RETENCION_RENTA_BAJA/100.0;
			else
				if(es_soltero)
					retencion = retencion + retencion * RETENCION_SOLTEROS/100.0;
				else
					retencion = retencion + retencion * RETENCION_CASADOS/100.0;
		}
	
	indice_variacion = 1 - retencion/100.0;
	renta_neta = renta_bruta * indice_variacion;
	
	cout << mensaje_final << renta_neta << " euros.\n";
	system("pause");
}
