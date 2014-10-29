#include <iostream>
#include <cctype>

using namespace std;

struct Deposit{
		double capital;
		double interest;
		double total;
};

double ask_for_capital(void);
double ask_for_interest(void);
unsigned int calc_number_years_to_double(Deposit);
double calc_new_capital(double, double);
void show_result(unsigned int);

int main(){

	Deposit deposit;
	deposit.total = 0.0;
	deposit.interest = 0.0;
	deposit.capital = 0.0;
	unsigned int number_years;

	deposit.capital = ask_for_capital();
	deposit.interest = ask_for_interest();
	number_years = calc_number_years_to_double(deposit);

	show_result(number_years);
	return 0;
}

double ask_for_capital(){
	double capital;

	cout << "How much money do you want to deposit? ";
	cin >> capital;

	return capital;
}

double ask_for_interest(){
	double interest;

	cout << "What will the interest be? ";
	cin >> interest;

	return interest;
}

unsigned int calc_number_years_to_double(Deposit deposit){
	unsigned int number_years = 0;
	double double_capital = deposit.capital * 2;

	for (deposit.total = deposit.capital;
		 deposit.total < double_capital;
		 number_years++){

		deposit.total = calc_new_capital(deposit.total, deposit.interest);
	}

	return number_years;
}

double calc_new_capital(double capital, double interest){
	return capital + (capital * interest / 100);
}

void show_result(unsigned int years){
	cout << "Years required to double capital: ";
	cout << years << endl;
}