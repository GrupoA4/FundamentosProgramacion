#include<iostream>
using namespace std;

int ask_number(void);
bool check_torn(int);
int number_of_digits(int);
int split_head(int, int);
int split_tail(int, int);
int pow(int, int);
bool check_torn_parts(int, int, int);
void show_result(bool);


int main(){
	int number;
	bool is_torn;

	number = ask_number();
	cout << "compruebo";
	is_torn = check_torn(number);

	show_result(is_torn);
}

int ask_number(){
	int number;

	cout << "Enter a number to check it\n >  ";
	cin >> number;
	cout << endl;
	cout << "recibido";

	return number;
}

bool check_torn(int number){
	int division_point;
	int head;
	int tail;
	bool is_torn = false;

	division_point = number_of_digits(number) - 1;
	cout << "comienzo a partir";
	for (division_point; division_point > 0 || is_torn == false; division_point --){
		head = split_head(number, division_point);
		tail = split_tail(number, division_point);
		is_torn = check_torn_parts(number, head, tail);
	}

	return is_torn;
}

int number_of_digits(int number){
	int digits = 1;

	while(number >= 10){
   		number /= 10;
   		++digits;
	}

	return digits;
}

int split_head(int number, int split_point){
	int head;

	switch (split_point){
		case 0: head = number; break;
		case 1: head = number / 10; break;
		case 2: head = number / 100; break;
		case 3: head = number / 1000; break;
		case 4: head = number / 10000; break;
		default: head = number / pow(10, split_point);
	}

	return head;
}

int split_tail(int number, int split_point){
	int tail;

	switch (split_point){
		case 0: tail = number; break;
		case 1: tail = number % 10; break;
		case 2: tail = number % 100; break;
		case 3: tail = number % 1000; break;
		case 4: tail = number % 10000; break;
		default: tail = number % pow(10, split_point);
	}

	return tail;
}

int pow(int base, int index){
	int result = base;

	for(index-1; index < 0; index--){
		result *= base;
	}
}

bool check_torn_parts(int number, int head, int tail){
	bool is_torn;

	is_torn = (head + tail)*(head + tail) == number;

	return is_torn;
}

void show_result(bool is_torn){
	string msg;

	switch(is_torn){
		case true: msg = "Yea! It's torn"; break;
		case false: msg = "It isn't torn"; break;
	}

	cout << msg << endl;
}