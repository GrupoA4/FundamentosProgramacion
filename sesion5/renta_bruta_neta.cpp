#include <iostream>
#include <cctype>
using namespace std;

struct FiscalPerson{
	bool self_employed;
	bool pensioner;
	char civil_status;
	double initial_rent;
	float retention;
	double final_rent;
};

FiscalPerson get_fiscal_data();
bool is_self_employed();
bool is_pensioner();
bool response_to_bool(char);
char ask_civil_status();
bool check_civil_status_response(char);
double ask_initial_rent();
float ask_initial_retention();
FiscalPerson calc_rent(FiscalPerson);
float calc_retention(FiscalPerson);
float calc_standard_retention(FiscalPerson);
void show_result(FiscalPerson);


int main(){
	FiscalPerson fiscal_person;

	fiscal_person = get_fiscal_data();
	fiscal_person = calc_rent(fiscal_person);

	show_result(fiscal_person);
	return 0;
}

FiscalPerson get_fiscal_data(){
	FiscalPerson person;

	person.self_employed = is_self_employed();
	person.pensioner = is_pensioner();
	person.civil_status = ask_civil_status();
	person.initial_rent = ask_initial_rent();
	person.retention = ask_initial_retention();

	return person;
}

bool is_self_employed(){
	char response;
	bool is_self_employed;

	cout << "Are you self-employed?s/n\n >  ";
	cin >> response;
	cout << endl;

	is_self_employed = response_to_bool(response);

	return is_self_employed;
}

bool is_pensioner(){
	char response;
	bool is_pensioner;

	cout << "Are you pensioner?s/n\n >  ";
	cin >> response;
	cout << endl;

	is_pensioner = response_to_bool(response);

	return is_pensioner;
}

bool response_to_bool(char response){
	bool result;
	response = tolower(response);

	if (response == 's'){
		result = true;
	} else {
		result = false;
	}

	return result;
}

char ask_civil_status(){
	char civil_status;
	bool is_valid;

	do{
	cout << "What is your civil status?\n";
	cout << "single -> s\n";
	cout << "married -> m\n";
	cout << "widow/er -> w\n";
	cout << " >  ";
	cin >> civil_status;
	cout << endl;

	is_valid = check_civil_status_response(civil_status);
	} while (!is_valid);

	return civil_status;
}

bool check_civil_status_response(char civil_status){
	char valid_responses[3] = {'s', 'm', 'w'};
	int size_valid_responses = sizeof valid_responses / sizeof valid_responses[0];
	bool is_valid = false;

	for (int i=0; i<size_valid_responses; i++){
		//if just one of the responses is valid, is_valid will be true.
		is_valid = is_valid || civil_status == valid_responses[i];
	}

	return is_valid;
}

double ask_initial_rent(){
	double rent;

	cout << "What is your rent?\n >  ";
	cin >> rent;
	cout << endl;

	return rent;
}

float ask_initial_retention(){
	double retention;

	cout << "What is the retention to apply?(%)\n >  ";
	cin >> retention;
	cout << endl;

	return retention;
}

FiscalPerson calc_rent(FiscalPerson person){

	person.retention = calc_retention(person);
	person.final_rent = person.initial_rent - person.initial_rent*(person.retention / 100);

	return person;
}

float calc_retention(FiscalPerson person){

	if (person.self_employed){
		person.retention -= 3;
	} else
	if (person.pensioner){
		person.retention += 1;
	} else {
		person.retention = calc_standard_retention(person);
	}

	return person.retention;
}

float calc_standard_retention(FiscalPerson person){
	person.retention += 2;

	if (person.initial_rent < 20000){
		person.retention += 6;
	} else
	if (person.civil_status = 'm' && person.initial_rent > 20000){
		person.retention += 8;
	} else
	if (person.civil_status = 's' && person.initial_rent > 20000){
		person.retention += 10;
	}

	return person.retention;
}

void show_result(FiscalPerson person){

	cout << "Has been applied a retention of ";
	cout << person.retention << "%\n";
	cout << "The final rent is " << person.final_rent;
	cout << endl;
}