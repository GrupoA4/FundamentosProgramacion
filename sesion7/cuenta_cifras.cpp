#include<iostream>
#include<vector>
using namespace std;

int ask_digit(void);
vector<int> ask_range(void);
int count_digits_in_range(int, vector<int>);
vector<int> range_to_set(vector<int>);
int count_digits_in_number(int, int);
void show_result(int);


int main(){
	int digit;
	vector<int> range(2);
	int count;

	digit = ask_digit();
	range = ask_range();
	count = count_digits_in_range(digit, range);

	show_result(count);
	return 0;
}

int ask_digit(){
	int digit;

	cout << "What digit do you want to count? ";
	cin >> digit;
	cout << endl;

	return digit;
}

vector<int> ask_range(){
	vector<int> range(2);
	int min;
	int max;

	cout << "Enter a range defined by a minimum and a maximum:\n";
	cout << "Min: ";
	cin >> range[0];
	cout << "\nMax: ";
	cin >> range[1];
	cout << endl;

	range[0] = min;
	range[1] = max;

	return range;
}

int count_digits_in_range(int digit, vector<int> range){
	int count = 0;
	vector<int> set;

	set = range_to_set(range);
	for(int i=0; i < set.size(); i++){
		count += count_digits_in_number(range[i], digit);
	}

	return count;
}

vector<int> range_to_set(vector<int> range){
	vector<int> set;

	for (int i=range[0]; i <= range[1]; i++){
		set.push_back(i);
	}

	return set;
}

int count_digits_in_number(int number, int digit){
	int count = 0;
	int split_digit;

	for (int i=1; number/i > 0; i*=10){
		split_digit = (number / i) % 10;
		if (split_digit == digit) count++;
	}

	return count;
}

void show_result(int count){
	cout << "The total of digits in the range is " << count;
	cout << endl;
}