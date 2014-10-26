#include <iostream>
using namespace std;

int ask_for_age(void);
double ask_for_salary(void);
void raise_salary(int, double);
void raise(double, int);

int main(){
	int age;
	double salary;
	bool can_be_raised;

	age = ask_for_age();
	salary = ask_for_salary();

	raise_salary(age, salary);
	return 0;
}

int ask_for_age(){
	int age;

	cout << "What is the age? ";
	cin >> age;
	cout << endl;

	return age;
}

double ask_for_salary(){
	double salary;

	cout << "And the salary? ";
	cin >> salary;
	cout << endl;

	return salary;
}

void raise_salary(int age, double salary){
	const bool OLDER = age > 65;
	const bool YOUNGER = age < 35;
	const bool LOW_SALARY = salary < 300;
	bool can_be_raised = true;
	double rise;

	if (OLDER || YOUNGER){
		rise = 4;
	}else {
		can_be_raised = false;
	}

	if ((OLDER || YOUNGER) && LOW_SALARY){
		rise += 3;
	} 

	if (can_be_raised){
		raise(salary, rise);
	}else{
		cout << "Salary can't be raised\n";
	}
}

void raise(double salary, int rise){
	double percent = rise / 100.0;
	int new_salary = salary + (salary * percent);

	cout << "Congratulations, your salary now is " << new_salary << "\n";
	cout << "The rise was " << rise << "%";
	cout << endl;
} 