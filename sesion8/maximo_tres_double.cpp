#include<iostream>
using namespace std;

double ask_value(string);
double Max(double, double, double);
void show_result(double);


int main(){
	double first_value;
	double second_value;
	double third_value;
	double maximum;

	first_value = ask_value("first");
	second_value = ask_value("second");
	third_value = ask_value("third");

	maximum = Max(first_value, second_value, third_value);

	show_result(maximum);
	return 0;
}

double ask_value(string tag){
	double value;

	cout << "Give me the " << tag << " value\n >  ";
	cin >> value;
	cout << endl;

	return value;
}

double Max(double first, double second, double third){
	double maximum;

	if (first > second){
		maximum = first;
	} else {
		maximum = second;
	}

	if (third > maximum) {
		maximum = third;
	}

	return maximum;
}

void show_result(double maximum){
	cout << "The greater number is " << maximum << endl;
}