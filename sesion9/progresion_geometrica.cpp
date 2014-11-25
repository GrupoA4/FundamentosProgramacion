#include<iostream>
#include<cmath>
using namespace std;

class GeometricalProgression{
	private:
		double first_term;
		double r;

	public:
		GeometricalProgression(double _first_term, double _r){
			first_term = _first_term;
			r = _r;
		}

		double term(int term_index){
			double term;

			term = first_term * pow(r, term_index-1);

			return term;
		}

		double sum_up_to(int top){
			double result;

			result = first_term * ((pow(r, top) - 1) / (r-1));

			return result;
		}

		double sum_up_to_infinite(){
			double result;

			result = first_term / (1-r);

			return result;
		}

		double product_to(int top){
			double last_term;
			double product;
			double square;
			double result;

			last_term = term(top);
			product = first_term * last_term;
			square = pow (product, top);
			result = sqrt(square);

			return result;
		}
};


GeometricalProgression ask_progression(void);
double ask_first_term(void);
double ask_progression_factor(void);
int ask_top(void);
void print_terms_untill_top(GeometricalProgression, int);
void print_term(double);
void show_sum_untill_top(GeometricalProgression, int);


int main(){
	int top;
	double sum;

	GeometricalProgression progression = ask_progression();
	top = ask_top();

	print_terms_untill_top(progression, top);
	show_sum_untill_top(progression, top);
}

GeometricalProgression ask_progression(){
	double first_term;
	double factor;

	cout << "Enter the values to create a geometrical progression:\n";
	first_term = ask_first_term();
	factor = ask_progression_factor();
	GeometricalProgression progression(first_term, factor);

	return progression;
}

double ask_first_term(){
	double term;

	cout << "What is the first term of the progression?\n >  ";
	cin >> term;
	cout << endl;

	return term;
}

double ask_progression_factor(){
	double factor;

	cout << "What is the progression factor?\n >  ";
	cin >> factor;
	cout << endl;

	return factor;
}

int ask_top(){
	int top;

	cout << "What is the top of the progression?\n >  ";
	cin >> top;
	cout << endl;

	return top;
}

void print_terms_untill_top(GeometricalProgression progression, int top){
	double term;

	cout << "Terms of the progression until " << top <<":\n";
	for (int i=1; i <= top; i++){
		term = progression.term(i);
		print_term(term);
	}
}

void print_term(double term){
	cout << term << endl;
}

void show_sum_untill_top(GeometricalProgression progression, int top){
	double sum;

	sum = progression.sum_up_to(top);

	cout << "The sum untill " << top << " is: " << sum;
	cout << endl;
}