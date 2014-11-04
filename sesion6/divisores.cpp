#include <iostream>
#include <vector>
using namespace std;

unsigned int ask_int(void);
bool check(unsigned int);
vector<unsigned int> calc_divisors(unsigned int);
void show_results(vector<unsigned int>);
void show_result(unsigned int);

int main(){
	unsigned int top;
	vector<unsigned int> divisors;

	top = ask_int();
	divisors = calc_divisors(top);

	show_results(divisors);
	return 0;
}

unsigned int ask_int(){
	bool is_valid;
	unsigned int number;

	cout << "Give me a positive integrer\n  > ";
	cin >> number;
	cout << endl;

	is_valid = check(number);

	while (!is_valid){
		cout << "It must be positive";
		cin >> number;
		cout << endl;

		is_valid = check(number);
	}

	return number;
}

bool check(unsigned int number){
	return number > 0;
}

vector<unsigned int> calc_divisors(unsigned int number){
	bool is_divisor;
	vector<unsigned int> divisors;

	for (unsigned int divisor=number; divisor>0; divisor--){
		is_divisor = !(number % divisor);

		if (is_divisor){
			divisors.push_back(divisor);
		}
	}

	return divisors;
}

void show_results(vector<unsigned int> divisors){

	cout << "Divisors are:\n";

	for (int i=0; i<divisors.size(); i++){
		show_result(divisors[i]);
	}
}

void show_result(unsigned int divisor){
	cout << "  - " << divisor;
	cout << endl;
}