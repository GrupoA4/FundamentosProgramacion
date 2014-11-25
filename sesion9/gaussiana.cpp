#include<iostream>
#include<cmath>
using namespace std;

class GaussFunction{
	private:
		double mean;
		double deviation;

	public:
		GaussFunction(double _mean, double _deviation){
			mean = _mean;
			deviation = _deviation;
		}

		double solve_by_x(double abscissa){
			double result;
			long double division_exponent;
			long double exponent;
			long double exponentiated_e;
			double division;

			//The function structure is:
			//f(x)= division * e^((-1/2) * (division_exponent)^2) ==>
			//f(x)= division * e^exponent ==> f(x)= division * exponentiated_e

			division = 1 / (deviation * sqrt(2*M_PI));
			division_exponent = (abscissa - mean) / deviation;
			exponent = (-1/2) * pow(division_exponent, 2);
			exponentiated_e = pow(M_E, exponent);
			result = division * exponentiated_e;

			return result;
		}

		double cdf(int abscissa){
			double area;
			double ordered;
			double t;
			const double b_0 = 0.2316419;
			const double b_1 = 0.319381530;
			const double b_2 = -0.356563782;
			const double b_3 = 1.781477937;
			const double b_4 = -1.821255978;
			const double b_5 = 1.330274429;

			ordered = solve_by_x(abscissa);
			t = 1 / (1 + b_0*abscissa);
			area = (1 - ordered) * (b_1*t + b_2*t + b_3*t + b_4*t + b_5*t);

			return area;
		}
};


double ask_mean(void);
double ask_deviation(void);
int ask_number_values(void);
void print_gauss_function(GaussFunction, int);
void show_result(int, double, double);


int main(){
	double mean;
	double standard_deviation;
	int number_of_values;

	mean = ask_mean();
	standard_deviation = ask_deviation();
	number_of_values = ask_number_values();
	GaussFunction gauss_function(mean, standard_deviation);

	print_gauss_function(gauss_function, number_of_values);
	return 0;
}

double ask_mean(){
	double mean;

	cout << "Enter the mean of the gaussian function\n >  ";
	cin >> mean;
	cout << endl;

	return mean;
}

double ask_deviation(){
	double deviation;

	cout << "Enter the deviation of the gaussian function\n >  ";
	cin >> deviation;
	cout << endl;

	return deviation;
}

int ask_number_values(){
	int number_of_values;

	cout << "How many values do you want calc\n >  ";
	cin >> number_of_values;
	cout << endl;

	return number_of_values;
}

void print_gauss_function(GaussFunction function, int number_of_values){
	double ordered_value;
	double area;

	for (int i=0; i<=number_of_values; i++){
		ordered_value = function.solve_by_x(i);
		area = function.cdf(i);
		show_result(i, ordered_value, area);
	}
}

void show_result(int abcissa_value, double ordered_value, double area){
	cout << "g(" << abcissa_value << ") = " << ordered_value;
	cout << "  area = " << area;
	cout << endl;
}