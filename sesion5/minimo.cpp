#include <iostream>
#include <vector>
using namespace std;

vector<int> ask_numbers();
int read_number(void);
void delete_zero(vector<int>*);
int calc_minimum(vector<int>);
int get_minimum(int, int);
void show_result(int);
void end(void);
void show_minimum(int);


int main(){
	vector<int> numbers;
	int minimum;

	numbers = ask_numbers();
	minimum = calc_minimum(numbers);

	show_result(minimum);
	return 0;
}

vector<int> ask_numbers(){
	vector<int> numbers;
	int number;
	bool is_zero = false;

	cout << "Enter some numbers, ends with zero\n";

	while (!is_zero){
		number = read_number();
		numbers.push_back(number);
		is_zero = number == 0;
	}

	delete_zero(&numbers);

	return numbers;
}

int read_number(){
	int number;

	cout << " >  ";
	cin >> number;
	cout << endl;

	return number;
}

void delete_zero(vector<int> *numbers){
	if (numbers->size() > 1){
		numbers->pop_back();
	}
}

int calc_minimum(vector<int> numbers){
	int minimum = numbers[0];

	for (int i=0; i<numbers.size(); i++){
		minimum = get_minimum(minimum, numbers[i]);
	}

	return minimum;
}

int get_minimum(int number_one, int number_two){
	int minimum;

	if (number_one < number_two){
		minimum = number_one;
	} else {
		minimum = number_two;
	}

	return minimum;
}

void show_result(int minimum){

	if (minimum == 0){
		end();
	} else {
		show_minimum(minimum);
	}
}

void end(){
	cout << "Colsing without result";
	cout << endl;
}

void show_minimum(int minimum){
	cout << "Smallest number is " << minimum;
	cout << endl;
}