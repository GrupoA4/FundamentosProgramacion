#include<iostream>
using namespace std;

void print_increasing_line(int, int);
int ask_rows_number(void);
int ask_initial_value(void);


class Pattern{

	public:
		Pattern(int _initial_value, int _rows_number) : initial_value(_initial_value), rows_number(_rows_number){}
		int initial_value;
		int rows_number;
};

class TrianglePattern : public Pattern{
	public:
		TrianglePattern(int _initial_value, int _rows_number) : Pattern(_initial_value, _rows_number) {}
		void print(void);
};

void TrianglePattern::print(){
	int rows_to_print = rows_number;
	int first_number = initial_value;

	while(rows_to_print > 0){
		print_increasing_line(first_number, rows_to_print);
		cout << endl;
		rows_to_print--;
		first_number++;
	}
}

class SquarePattern : public Pattern{
	public:
		SquarePattern(int _initial_value, int _rows_number) : Pattern(_initial_value, _rows_number) {}
		void print(void);
};

void SquarePattern::print(){
	int rows_to_print = rows_number;
	int first_number = initial_value;

	while(rows_to_print > 0){
		print_increasing_line(first_number, rows_number);
		cout << endl;
		rows_to_print--;
		first_number++;
	}
}

void print_increasing_line(int first, int top){
	for (int i=0; i < top; i++){
		cout << first + i;
	}
}



int main(){
	int rows_number;
	int initial_value;

	rows_number = ask_rows_number();
	initial_value = ask_initial_value();
	TrianglePattern triangle(initial_value, rows_number);
	SquarePattern square(initial_value, rows_number);

	triangle.print();
	cout << endl << endl;
	square.print();
	cout << endl << endl;
	return 0;
}

int ask_rows_number(){
	int number;

	cout << "How many rows dou you want to give to the shapes? ";
	cin >> number;
	cout << endl;

	return number;
}

int ask_initial_value(){
	int value;

	cout << "What do you want it be the initial value? ";
	cin >> value;
	cout << endl;

	return value;
}