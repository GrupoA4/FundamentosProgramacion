#include <iostream>
#include <string>
using namespace std;

char ask_for_char();
char to_lower(char);
bool is_upper(char);
void reply(bool, string, string);
void show_result(char);


int main(){
	char letter;

	letter = ask_for_char();
	letter = to_lower(letter);

	show_result(letter);
	return 0;
}

char ask_for_char(){
	char character;
	bool is_uppercase;

	do{
		cout << "Give me a capital letter: ";
		cin >> character;
		cout << endl;

		is_uppercase = is_upper(character);

		reply(is_uppercase, "Thanks", "I need an upercase!");
	}while(!is_uppercase);

	return character;
}

bool is_upper(char character){
	bool is_upper;

	is_upper = character >= 'A' && character <= 'Z';

	return is_upper;
}

void reply(bool is_valid, string ok_msg, string error_msg){
	string response_msg;

	if (is_valid){
		response_msg = ok_msg;
	} else {
		response_msg = error_msg;
	}

	cout << response_msg << endl;
}

char to_lower(char character){
	int distance_upper_lower = 'a' - 'A';

	character = character + distance_upper_lower;
	return character;
}

void show_result(char letter){
	cout << "... ... ...\n";
	cout << "Voila, your letter has been converted into " << letter;
	cout << endl;
}