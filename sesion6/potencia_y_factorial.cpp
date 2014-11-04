#include<iostream>
using namespace std;

double ask_base(void);
int ask_index(void);
double pow(double, int);
double pow_non_zero(double, int);
double fact(double);
void show_result(double, double);


int main(){
	double base;
	int index;
	double power;
	double factorial;

	base = ask_base();
	index = ask_index();
	power = pow(base, index);
	factorial = fact(base);

	show_result(power, factorial);
}

double ask_base(){
	double base;

	cout << "Guive me a number to operate with it\n >  ";
	cin >> base;
	cout << endl;

	return base;
}

int ask_index(){
	int index;

	cout << "And a index to make an exponentiation\n >  ";
	cin >> index;
	cout << endl;

	return index;
}

double pow(double base, int index){
	double result;

	switch (index){
		case 0: result = 1; break;
		default: result = pow_non_zero(base, index);
	}

	return result;
}

double pow_non_zero(double base, int index){
	double result = base;

	for (index; index > 1; index--){
		result *= base;
	}

	return result;
}

double fact(double base){
	double result = 1;

	for (base; base > 0; base--){
		result *= base;
	}

	return result;
}

void show_result(double power, double factorial){
	cout << "The exponentiation is: " << power << endl;
	cout << "And the factorial is: " << factorial << endl;
}