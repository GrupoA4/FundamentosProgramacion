#include <iostream>
using namespace std;

char ask_for_char();
char to_lower(char);
bool is_upper(char);
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

	cout << "Give me a letter: ";
	cin >> character;
	cout << endl;

	return character;
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

void show_result(char letter){
	cout << "... ... ...\n";
	cout << "Voila, your letter has been converted into " << letter;
	cout << endl;
}