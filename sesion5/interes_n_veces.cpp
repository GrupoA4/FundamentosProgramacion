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
double ask_number_of_years(void);
double calc_result(double, double);
void show_results(Deposit, unsigned int);
void show_result(double, unsigned int);

int main(){

	Deposit deposit;
	deposit.total = 0.0;
	deposit.interest = 0.0;
	deposit.capital = 0.0;
	unsigned int number_years;

	deposit.capital = ask_for_capital();
	deposit.interest = ask_for_interest();
	number_years = ask_number_of_years();
	deposit.total = calc_result(deposit.capital, deposit.interest);

	show_results(deposit, number_years);

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

double ask_number_of_years(){
	unsigned int years;

	cout << "How many years the money will be in? ";
	cin >> years;

	return years;
}

double calc_result(double capital, double interest){
	return capital + (capital * interest / 100);
}

void show_results(Deposit deposit, unsigned int number_years){

	for (unsigned int i=1; i<=number_years; i++){

		deposit.total = calc_result(deposit.total, deposit.interest);

		show_result(deposit.total, i);
	}
}

void show_result(double total, unsigned int year){
	cout << "Total in year " << year << ": ";
	cout << total << endl;
}