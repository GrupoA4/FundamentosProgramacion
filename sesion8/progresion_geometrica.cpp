#include<iostream>
#include<cmath>
using namespace std;

double ask_first_term(void);
double ask_progression_factor(void);
int ask_top(void);
double sum_up_to(double, double, int);
double sum_up_to_infinite(double, double);
double product_to(double, double, int);
double my_pow(double, int);
double pow_non_zero(double, int);
void show_result(string, double);


int main(){
	double first_term;
	double factor;
	int top;
	double summation;
	double infinite_summation;
	double product;

	first_term = ask_first_term();
	factor = ask_progression_factor();
	top = ask_top();

	summation = sum_up_to(first_term, factor, top);
	infinite_summation = sum_up_to_infinite(first_term, factor);
	product = product_to(first_term, factor, top);

	show_result("summation", summation);
	show_result("infinite summation", infinite_summation);
	show_result("product", product);
}

double ask_first_term(){
	double term;

	cout << "What is the first term of the progression?\n >  ";
	cin >> term;
	cout << endl;

	return term;
}

double ask_progression_factor(){
	double factor;

	cout << "What is the progression factor?\n >  ";
	cin >> factor;
	cout << endl;

	return factor;
}

int ask_top(){
	int top;

	cout << "What is the top of the progression?\n >  ";
	cin >> top;
	cout << endl;

	return top;
}

double sum_up_to(double first_term, double factor, int top){
	double new_term = first_term;
	double result = first_term;

	result = first_term * ((my_pow(factor, top) - 1) / (factor-1));

	return result;
}

double sum_up_to_infinite(double first_term, double factor){
	double result;

	result = first_term / (1-factor);

	return result;
}

double product_to(double first_term, double factor, int top){
	double last_term;
	double product;
	double square;
	double result;

	last_term = sum_up_to(top, factor, top);
	product = first_term * last_term;
	square = my_pow (product, top);
	result = sqrt(square);

	return result;
}

double my_pow(double base, int index){
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

void show_result(string tag, double result){
	cout << "The " << tag << " of the progression is " << result;
	cout << endl;
}