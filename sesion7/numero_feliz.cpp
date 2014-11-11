#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

long ask_number(void);
int ask_grade(void);
bool check_happiness(int, int);
vector<int> divide_in_digits(int);
int number_of_digits(int);
int calc_square_summation(vector<int>);
int calc_square_summation(int, int);
void show_result(bool);


int main(){
	int grade;
	int number;
	bool is_happy;

	number = ask_number();
	grade = ask_grade();
	is_happy = check_happiness(number, grade);

	show_result(is_happy);
	return 0;
}

long ask_number(){
	long number;

	cout << "Enter a number to check if is happy\n >  ";
	cin >> number;
	cout << endl;

	return number;
}

int ask_grade(){
	int grade;

	cout << "Enter the grade to check with\n >  ";
	cin >> grade;
	cout << endl;

	return grade;
}

bool check_happiness(int number, int grade){
	bool is_happy;
	int iteration_result;
	vector<int> digits = divide_in_digits(number);

	for (int i=0; i<=grade && iteration_result!=1; i++){
		iteration_result = calc_square_summation(digits);
	}

	is_happy = iteration_result == 1;

	return is_happy;
}

vector<int> divide_in_digits(int number){
	int digit;
	vector<int> digits;
	int size = number_of_digits(number);
	long long divisor = (long long)pow(10.0, size-1);

	for (int i=0; i <= size; i++){
		digit = (number / divisor) % 10;
		digits.push_back(digit);
		divisor /= 10;
	}

	return digits;
}

int number_of_digits(int number){
	int digits = 1;

	while(number >= 10){
   		number /= 10;
   		++digits;
	}

	return digits;
}

int calc_square_summation(vector<int> terms){
	int result = 0;
	int number_terms = terms.size();
	bool odd_size = number_terms % 2;

	if (odd_size){
		terms.push_back(0);
	}

	for (int i=0; i < number_terms; i+=2){
		result += calc_square_summation(terms[i], terms[i+1]);
	}

	return result;
}

int calc_square_summation(int term_1, int term_2){
	int result;

	result = term_1*term_1 + term_2*term_2;

	return result;
}

void show_result(bool is_happy){
	string msg;

	if (is_happy){
		msg = "Your number is really happy :)";
	} else {
		msg = "Your number is sad :(";
	}

	cout << msg << endl;
}