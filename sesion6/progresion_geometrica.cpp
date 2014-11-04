#include<iostream>
using namespace std;

double ask_first_term(void);
double ask_progression_factor(void);
double ask_top(void);
double gprogression_summation(double, double, int);
void show_result(double);


int main(){
	double progression_factor;
	double first_term;
	int top;
	double result;

	first_term = ask_first_term();
	progression_factor = ask_progression_factor();
	top = ask_top();

	result = gprogression_summation(first_term, progression_factor, top);

	show_result(result);
	return 0;
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

double ask_top(){
	double top;

	cout << "What is the top of the progression?\n >  ";
	cin >> top;
	cout << endl;

	return top;
}

double gprogression_summation(double first_term, double factor, int top){
	double new_term = first_term;
	double result = first_term;

	for (int i=2; i <= top; i++){
		new_term *= factor;
		result += new_term;
	}

	return result;
}

void show_result(double result){
	cout << "The result is: " << result;
	cout << endl;
}