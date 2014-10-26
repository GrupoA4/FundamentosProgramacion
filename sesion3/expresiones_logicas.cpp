#include <iostream>
#include <string>
using namespace std;

void expression_1(void);
void expression_2(void);
void expression_3(void);
void show_response(string, bool);
char ask_for_letter(void);
bool is_lowercase(char);
int ask_for_age(void);
bool is_outside(int, int, int);
int ask_for_year(void);
bool is_leap(int);

int main(){
	cout << boolalpha;

	expression_1();
	expression_2();
	expression_3();
	
	return 0;
}

void expression_1(){
	char letter;

	letter = ask_for_letter();

	show_response("The letter is lowercase", is_lowercase(letter));
}

char ask_for_letter(){
	char letter;

	cout << "Pass me one letter: ";
	cin >> letter;
	cout << endl;

	return letter;
}

bool is_lowercase(char letter){
	bool is_lowercase;

	is_lowercase = letter > 97 && letter < 122;

	return is_lowercase;
}

void expression_2(){
	int age;

	age = ask_for_age();

	show_response("The age is smaller than 18 and higher than 65", is_outside(age, 18, 65));
}

int ask_for_age(){
	int age;

	cout << "Pass me one age: ";
	cin >> age;
	cout << endl;

	return age;
}

bool is_outside(int value, int bottom, int top){
	bool is_outside;

	is_outside = value < bottom || value > top;

	return is_outside;
}

void expression_3(){
	int year;

	year = ask_for_year();
	
	show_response("Is leap year", is_leap(year));
}

int ask_for_year(){
	int year;

	cout << "Pass me one year: ";
	cin >> year;
	cout << endl;

	return year;
}

bool is_leap(int year){
	bool is_leap;

	is_leap = (year % 4) == 0 || (year % 400) == 0;

	return is_leap;
}

void show_response(string response, bool result){
	cout << response << ": " << result;
	cout << endl;
}
