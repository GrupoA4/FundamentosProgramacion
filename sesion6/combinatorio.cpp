#include<iostream>
#include<string>
using namespace std;

double ask_number(string);
double calc_combinatorial(double,double);
double fact(double);
void show_result(double);


int main(){
	double first_number;
	double second_number;
	double combiatorial;

	first_number = ask_number("first");
	second_number = ask_number("second");
	combiatorial = calc_combinatorial(first_number, second_number);

	show_result(combiatorial);
}

double ask_number(string tag){
	double number;

	cout << "Give me the " << tag << " term\n >  ";
	cin >> number;
	cout << endl;

	return number;
}

double calc_combinatorial(double first_number,double second_number){
	double result;

	result = fact(first_number) / (fact(second_number) - fact(first_number-second_number));

	return result;
}

double fact(double base){
	double result = 1;

	for (base; base > 0; base--){
		result *= base;
	}

	return result;
}

void show_result(double combiatorial){
	cout << "The result is " << combiatorial << endl;
}