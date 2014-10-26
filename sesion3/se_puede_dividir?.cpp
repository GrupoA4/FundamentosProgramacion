#include <iostream>
using namespace std;

int ask_value();
bool can_be_divided(int, int);
void show_result(bool);

int main(){
	int value_1;
	int value_2;
	bool is_divisible;

	value_1 = ask_value();
	value_2 = ask_value();

	is_divisible = can_be_divided(value_1, value_2);

	show_result(is_divisible);
	return 0;
}

int ask_value(){
	int value;

	cout << "Value to be divided: ";
	cin >> value;
	cout << endl;

	return value;
}

bool can_be_divided(int val_1, int val_2){
	bool can_be;

	can_be = (bool)!(val_1 % val_2);

	return can_be;
}

void show_result(bool can_be){

	if (can_be){
		cout << "Yea! the values can be divided.";
	} else {
		cout << "I'm sorry, you can't divide these values.";
	}

	cout << endl;
}