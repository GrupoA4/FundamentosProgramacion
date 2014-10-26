#include <iostream>

using namespace std;

double ask_for_profits(void);
double calc_designer_profits(double, int);
double calc_maker_profits(double, int);
void show_results(double, double);

int main(){
	double profits = 0.0;
	double designer_profits = 0.0;
	double maker_profits = 0.0;
	int number_of_makers = 3;

	profits = ask_for_profits();
	designer_profits = calc_designer_profits(profits, number_of_makers);
	maker_profits = calc_maker_profits(profits, number_of_makers);

	show_results(designer_profits, maker_profits);

	return 0;
}

double ask_for_profits(){
	double profits = 0.0;

	cout << "How much money did you earn with the product? \n >  ";
	cin >> profits;

	return profits;
}

double calc_designer_profits(double profits, int number_of_makers){
	double designer_profits;
	
	designer_profits = profits / (1 + (number_of_makers * 0.5));

	return designer_profits;
}

double calc_maker_profits(double profits, int number_of_makers){
	double maker_profits;
	
	maker_profits = profits / (number_of_makers + 2);

	return maker_profits;
}

void show_results(double designer_profits, double maker_profits){
	cout << "The amount of money earned by the designer: " << designer_profits << endl;
	cout << "The amount of money earned by each maker: " << maker_profits << endl;
}