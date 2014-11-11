#include <iostream>
#include <utility>
#include <map>

using namespace std;

struct Deposit{
		double initial_capital;
		int interest;
		unsigned int years;
		double resulting_capital;
};

// Mapping types declaration
typedef pair<int, double> YearCapitalPair;
typedef map<int, double> YearCapitalMap;
typedef pair<int, YearCapitalMap> PercentYearsPair;
typedef map<int, YearCapitalMap> PercentYearsMap;

// Function prototypes
double ask_for_capital();
double ask_for_interest();
double ask_number_of_years();
PercentYearsMap calc_resulting_capital_by_interest_steps(Deposit deposit);
YearCapitalMap capital_by_each_year(Deposit deposit);
double calc_resulting_capital(Deposit deposit);
void show_result(PercentYearsMap map);
void show_year_capital_pairs(YearCapitalMap map);


int main(){
	Deposit deposit;
	PercentYearsMap main_map;

	deposit.initial_capital = ask_for_capital();
	deposit.interest = ask_for_interest();
	deposit.years = ask_number_of_years();

	main_map = calc_resulting_capital_by_interest_steps(deposit);

	show_result(main_map);
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
	cout << endl;

	return years;
}

PercentYearsMap calc_resulting_capital_by_interest_steps(Deposit deposit){
	int initial_interest = deposit.interest;
	YearCapitalMap year_capital_map;
	PercentYearsMap percent_years_map;

	/* Creates a pseudo-JSON with the shape:
		{//percent: object 
		  1: {//year: capital
				  1: capital,
				  2: capital,
				  ...
				}
		  2: ...
		}
	*/
	for (int i=1; i <= initial_interest; i++){
		deposit.interest = i;
		year_capital_map = capital_by_each_year(deposit);
		PercentYearsPair *percent_years_pair = new PercentYearsPair(i, year_capital_map);
		percent_years_map.insert(*percent_years_pair);
		delete percent_years_pair;
	}

	return percent_years_map;
}

YearCapitalMap capital_by_each_year(Deposit deposit){
	YearCapitalMap year_capital_map;

	/* Creates a pseudo-JSON with the shape:
		{//year: capital
		  1: capital,
		  2: capital,
		  ...
		}
	*/
	for (int i=1; i <= deposit.years; i++){
		deposit.initial_capital = calc_resulting_capital(deposit);
		YearCapitalPair *year_capital_pair = new YearCapitalPair(i, deposit.initial_capital);
		year_capital_map.insert(*year_capital_pair);
		delete year_capital_pair;
	}

	return year_capital_map;
}

double calc_resulting_capital(Deposit deposit){
	return deposit.initial_capital + (deposit.initial_capital * deposit.interest / 100);
}

void show_result(PercentYearsMap map){
	for (std::map<int, YearCapitalMap>::iterator it=map.begin(); it!=map.end(); ++it){
		cout << "Calcs with " << it->first << "%:\n";
		show_year_capital_pairs(it->second);
		cout << endl;
	}
}

void show_year_capital_pairs(YearCapitalMap map){
	for (std::map<int, double>::iterator it=map.begin(); it!=map.end(); ++it){
		cout << "Money obtained in the year number " << it->first << ": ";
		cout << it->second << endl;
	}
}