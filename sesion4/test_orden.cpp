#include <iostream>
#include <string>
using namespace std;

void get_numbers(int *);
bool are_ordered(int *);
bool ordered_high_to_low(int *);
bool ordered_low_to_high(int *);
void show_response(bool);

int main(){
	int numbers[3];
	bool ordered;

	get_numbers(numbers);
	ordered = are_ordered(numbers);

	show_response(ordered);
	return 0;
}

void get_numbers(int *numbers){
	cout << "Insert the first number.\n >  ";
	cin >> numbers[0];

	cout << "Insert the second number.\n >  ";
	cin >> numbers[1];

	cout << "Insert the last number.\n >  ";
	cin >> numbers[2];

	cout << endl;
}

bool are_ordered(int *numbers){
	bool ordered;

	if (ordered_high_to_low(numbers)){
		ordered = true;
	} else
	if (ordered_low_to_high(numbers)){
		ordered = true;
	} else {
		ordered = false;
	}

	return ordered;
}

bool ordered_high_to_low(int *numbers){
	bool ordered = true;

	for (int i=0; i<2; i++){
		// if only one term is lower than the next one, 'ordered' will be false
		ordered = ordered && (numbers[i] > numbers[i+1]);
	}

	return ordered;
}

bool ordered_low_to_high(int *numbers){
	bool ordered = true;

	for (int i=0; i<2; i++){
		// if only one term is higher than the next one, 'ordered' will be false
		ordered = ordered && (numbers[i] < numbers[i+1]);
	}

	return ordered;
}

void show_response(bool ordered){
	string msg;

	switch (ordered){
		case true: msg = "Numbers are ordered :)";
			break;
		case false: msg = "That is a disaster :(";
			break;
		default: msg = "Wtf???";
	}

	cout << msg;
	cout << endl;
}