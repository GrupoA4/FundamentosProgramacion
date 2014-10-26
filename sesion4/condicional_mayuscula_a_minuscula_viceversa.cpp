#include <iostream>
using namespace std;

char ask_for_char();
char swap_case(char);
char to_lower(char);
char to_upper(char);
bool is_upper(char);
bool is_lower(char);
void show_result(char);


int main(){
	char letter;

	letter = ask_for_char();
	letter = swap_case(letter);

	show_result(letter);
	return 0;
}

char ask_for_char(){
	char character;

	cout << "Give me a letter: ";
	cin >> character;
	cout << endl;

	return character;
}

char swap_case(char character){
	char converted_char;

	if (is_upper(character)){
		converted_char = to_lower(character);
	} else
	if (is_lower(character)){
		converted_char = to_upper(character);
	} else {
		converted_char = character;
	}

	return converted_char;
}

char to_lower(char character){

	if (is_upper(character)){
	character = character + 32;
	}

	return character;
}

bool is_upper(char character){
	bool is_upper;

	is_upper = character >= 'A' && character <= 'Z';

	return is_upper;
}

char to_upper(char character){

	if (is_lower(character)){
	character = character - 32;
	}

	return character;
}

bool is_lower(char character){
	bool is_lower;

	is_lower = character >= 'a' && character <= 'z';

	return is_lower;
}

bool is_alpha(char character){
	bool is_alpha;

	is_alpha = is_lower(character) || is_upper(character);

	return is_alpha;
}

void show_result(char letter){
	if (is_alpha(letter)){
		cout << "... ... ...\n";
		cout << "Voila, your letter has been converted into " << letter;
		cout << endl;
	} else {
		cout << "Error!!! The character must be a letter";
		cout << endl;
	}
}