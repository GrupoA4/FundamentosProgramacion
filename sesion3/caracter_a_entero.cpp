#include <iostream>
using namespace std;

char ask_for_number();
int char_to_int(char);
void show_result(int);

int main(){
	char c_number;
	int number;

	c_number = ask_for_number();
	number = char_to_int(c_number);

	show_result(number);
	return 0;
}

char ask_for_number(){
	char number;

	cout << "Give me a number between 0 and 9\n  > ";
	cin >> number;
	cout << endl;

	return number;
}

int char_to_int(char car){
	int number;

	number = car - 48;

	return number;
}

void show_result(int number){
	cout << "You number was " << number;
	cout << ", and trust me, now it is an int.";
	cout << endl;
}