#include <iostream>
#include <vector>
using namespace std;

int ask_for_number(void);
vector<int> divide(int number);
void show_results(vector<int>);
void show_result(int);

int main(){
	int original_number;
	vector<int> digits;

	original_number = ask_for_number();
	digits = divide(original_number);

	show_results(digits);
	return 0;
}

int ask_for_number(){
	int number;

	cout << "Give me a integrer number\n >";
	cin >> number;
	cout << endl;

	return number;
}

vector<int> divide(int number){
	int digit;
	vector<int> digits;

	for (int i=1; (float)number/i > 1; i=i*10){
		digit = (number / i) % 10;
		digits.push_back(digit);
	}

	return digits;
}

void show_results(vector<int> digits){
	cout << "Slash slash slash... \nNow you have ";
	for (int i=digits.size()-1; i>=0; i--){
		show_result(digits[i]);
	}
	cout << endl;
}

void show_result(int digit){
	
	cout << " " << digit;
}