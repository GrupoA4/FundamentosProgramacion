#include <iostream>
using namespace std;

char ask_for_char();
char to_upper(char);
void show_result(char);


int main(){
	char letter;

	letter = ask_for_char();
	letter = to_upper(letter);

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

char to_upper(char character){
	character = character - 32;

	return character;
}

void show_result(char letter){
	cout << "... ... ...\n";
	cout << "Voila, your letter has been converted into " << letter;
	cout << endl;
}