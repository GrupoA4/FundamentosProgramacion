#include <iostream>
#include <string>

using namespace std;

struct Person{
	string name;
	int age;
};

int ask_for_age(Person);
void switch_values(int*, int*);
void show_results(Person, Person);

int main(){
	Person pedro;
	pedro.name = "Pedro";
	Person juan;
	juan.name = "Juan";

	pedro.age = ask_for_age(pedro);
	juan.age = ask_for_age(juan);

	switch_values(&pedro.age, &juan.age);

	show_results(pedro, juan);

	return 0;
}

int ask_for_age(Person person){
	int age;

	cout << "How old is " << person.name << "?\n >  ";
	cin >> age;
	cout << endl;

	return age;
}

void switch_values(int *p_value_1, int *p_value_2){
	int temp_value_1 = *p_value_1;

	*p_value_1 = *p_value_2;
	*p_value_2 = temp_value_1;
}

void show_results(Person person_1, Person person_2){
	cout << "Now " << person_1.name << " is " << person_1.age << " years old\n";
	cout << "and " << person_2.name << " is " << person_2.age << " years old\n";
}