#include <iostream>
using namespace std;

struct Swap_number{
	int value;
	char name;
};

int ask_for_number(char);
void swap(int *, int *, int *);
void show_result(Swap_number);

int main(){
	Swap_number x;
	x.name = 'x';
	Swap_number y;
	y.name = 'y';
	Swap_number z;
	z.name = 'z';

	x.value = ask_for_number(x.name);
	y.value = ask_for_number(y.name);
	z.value = ask_for_number(z.name);

	swap(&x.value, &y.value, &z.value);

	show_result(x);
	show_result(y);
	show_result(z);
	return 0;
}

int ask_for_number(char name){
	int number;

	cout << "What integrer do you want to store in " << name << " ?  ";
	cin >> number;
	cout << endl;

	return number;
}

void swap(int *var_1, int *var_2, int *var_3){
//swap the values var_1 into var_2, var_2 into var_3,
//var_3 into var_1, using xor propieties.

	*var_1 = *var_1 xor *var_2 xor *var_3;
	*var_2 = *var_1 xor *var_2 xor *var_3;
	*var_3 = *var_1 xor *var_2 xor *var_3;
	*var_1 = *var_1 xor *var_2 xor *var_3;
}

void show_result(Swap_number s_number){
	cout << "Now " << s_number.value << " is bound to " << s_number.name << "!\n";
}