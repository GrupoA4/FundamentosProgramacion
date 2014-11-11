#include<iostream>
#include<vector>
using namespace std;

int ask_top(void);
vector<int> calc_triangle_numbers(int);
bool is_triangle(int);
void show_result(vector<int>);


int main(){
	vector<int> triangle_numbers;
	int top;

	top = ask_top();
	triangle_numbers = calc_triangle_numbers(top);

	show_result(triangle_numbers);
	return 0;
}

int ask_top(){
	int top;

	cout << "Enter a integer number:\n >  ";
	cin >> top;
	cout << endl;

	return top;
}

vector<int> calc_triangle_numbers(int top){
	vector<int> triangle_numbers;

	for (int i=1; i <= top; i++){
		if (is_triangle(i)) triangle_numbers.push_back(i);
	}

	return triangle_numbers;
}

bool is_triangle(int number){
	bool is_triangle = false;
	int summation = 0;

	for (int i=1; i < number && !is_triangle; i++){
		summation += i;
		is_triangle = summation == number;
	}

	return is_triangle;
}

void show_result(vector<int> numbers){

	cout << "Smaller triangle numbers:\n";
	for (int i=0; i < numbers.size(); i++){
		cout << numbers[i] << ", ";
	}
	cout << endl;
}