#include <iostream>
#include <string>
using namespace std;

int ask_for_year(void);
bool test_leap(int);
void show_result(bool);

int main(){
	int year;
	bool is_leap;

	year = ask_for_year();
	is_leap = test_leap(year);

	show_result(is_leap);
	return 0;
}

int ask_for_year(){
	int year;

	cout << "Pass me a year:\n >  ";
	cin >> year;
	cout << endl;

	return year;
}

bool test_leap(int year){
	bool is_leap;

	is_leap = (year % 4 == 0) || (year % 400 == 0);

	return is_leap;
}

void show_result(bool is_leap){
	string msg;

	switch (is_leap){
		case true: msg = "Oh, you have one more day that year";
			break;

		case false: msg = "Nope, this year isn't leap";
			break;
	}

	cout << msg;
	cout << endl;
}