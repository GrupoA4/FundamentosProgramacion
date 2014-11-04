#include<iostream>
using namespace std;

double ask_top(void);
double succession_summation(int);
double cacl_succession_term(int);
void show_result(double);


int main(){
	int top;
	double result;

	top = ask_top();

	result = succession_summation(top);

	show_result(result);
	return 0;
}

double ask_top(){
	double top;

	cout << "How many terms do you want to add?\n >  ";
	cin >> top;
	cout << endl;

	return top;
}

double succession_summation(int top){
	double result;
	double new_term;
	int signature = 1;

	for (int i=1; i <= top; i++){
		signature *= -1;
		new_term = cacl_succession_term(i) * signature;
		result += new_term;
	}

	return result;
}

double cacl_succession_term(int index){
	double result;

	result = (index*index - 1) / 2*index;

	return result;
}

void show_result(double result){
	cout << "The result is: " << result;
	cout << endl;
}