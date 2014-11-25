#include<iostream>
#include<string>
#include<boost/lexical_cast.hpp>
using namespace std;

class Line{
	private:

		double a;
		double b;
		double c;

		void set_coefficents(double _a, double _b, double _c){
			a = _a;
			b = _b;
			c = _c;
			rectify_coefficents();
		}

		void rectify_coefficents(){
			if(bad_coefficents()){
				b = 1;
			}
		}

		bool bad_coefficents(){
			bool check;

			if (a==0 && b==0){
				check = true;
			} else {
				check = false;
			}

			return check;
		}

	public:

		Line(double a, double b, double c){
			set_coefficents(a, b, c);
		}

		double get_a(){
			return a;
		}

		double get_b(){
			return b;
		}

		double get_c(){
			return c;
		}

		double get_slope(){
			double slope;

			slope = -a / b;

			return slope;
		};

		double solve_by_y(double abscissa){
			double ordered;

			ordered = (-c - abscissa*a) / b;

			return ordered;
		}

		double solve_by_x(double ordered){
			double abscissa;

			abscissa = (-c - ordered*b) / a;

			return abscissa;
		}

		string to_string(){
			string str;

			str = boost::lexical_cast<std::string>(a) + "x" + " + " +
				  boost::lexical_cast<std::string>(b) + "y" + " + " +
				  boost::lexical_cast<std::string>(c) + " = 0 ";

			return str;
		}
};

Line ask_line(string tag);
double ask_coefficient(char);
double ask_axis_value(char);
void show_result(Line);
void show_solved_line(Line, double, double);


int main(){
	double given_abscissa, given_ordered;
	double solved_ordered, solved_abscissa;

	Line line = ask_line("first");
	Line other_line = ask_line("second");

	show_result(line);
	show_result(other_line);

	given_abscissa = ask_axis_value('x');
	given_ordered = ask_axis_value('y');

	solved_ordered = line.solve_by_x(given_abscissa);
	solved_abscissa = line.solve_by_y(given_ordered);

	show_solved_line(line, given_abscissa, solved_ordered);
	show_solved_line(line, solved_abscissa, given_ordered);
	return 0;
}

Line ask_line(string tag){
	double a, b, c;

	cout << "Enter the coefficients of the " << tag << " line\n";
	a = ask_coefficient('a');
	b = ask_coefficient('b');
	c = ask_coefficient('c');
	Line line(a, b, c);
	
	return line;
}

double ask_coefficient(char tag){
	double coefficient;

	cout << "Enter the coefficient " << tag << "\n >  ";
	cin >> coefficient;
	cout << endl;

	return coefficient;
}

void show_result(Line line){
	cout << "The slope of the line " << line.to_string();
	cout << "is " << line.get_slope();
	cout << endl;
}

double ask_axis_value(char tag){
	double axis_value;

	cout << "Enter the value for the axis " << tag << "\n >  ";
	cin >> axis_value;
	cout << endl;

	return axis_value;
}

void show_solved_line(Line line, double abscissa, double ordered){
	cout << "In " << line.to_string();
	cout << "with x=" << abscissa;
	cout << " -> " << "y=" << ordered;
	cout << endl;
}