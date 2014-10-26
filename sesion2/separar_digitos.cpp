#include <iostream>
using namespace std;

int ask_for_number(void);
void divide(int, int[]);
void show_result(int[]);

int main(){
	int original_number;
	int digits[3];

	original_number = ask_for_number();
	divide(original_number, digits);

	show_result(digits);
	return 0;
}

int ask_for_number(){
	int number;

	cout << "Give me a three digits number\n >";
	cin >> number;
	cout << endl;

	return number;
}

void divide(int number, int digits[]){
	digits[0] = (number / 100) % 10;
	digits[1] = (number / 10) % 10;
	digits[2] = number % 10;
}

void show_result(int digits[]){
	cout << "Slash slash slash... \nNow you have";
	cout << " " << digits[0];
	cout << " " << digits[1];
	cout << " " << digits[2];
	cout << endl;
}