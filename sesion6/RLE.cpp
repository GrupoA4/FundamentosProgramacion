#include<iostream>
#include<vector>
using namespace std;

vector<int> ask_sequence(void);
int ask_new_term(void);
vector<int> rle(vector<int>);
vector<int> count_consecutive_terms(int, vector<int>, int);
void show_result(vector<int>);


int main(){
	vector<int> input_sequence;
	vector<int> result_sequence;

	input_sequence = ask_sequence();
	result_sequence = rle(input_sequence);

	show_result(result_sequence);
	return 0;
}

vector<int> ask_sequence(){
	vector<int> sequence;
	int new_term = 0;

	cout << "Enter some numbers\n";

	while (new_term != -1){
		new_term = ask_new_term();
		sequence.push_back(new_term);
	}

	sequence.pop_back();

	if (sequence.size() == 0){
		sequence = ask_sequence();
	}

	return sequence;
}

int ask_new_term(){
	int term;

	cout << " >  ";
	cin >> term;
	cout << endl;

	return term;
}

vector<int> rle(vector<int> input){
	vector<int> result_sequence;
	vector<int> new_couple(2);
	int sample;
	int count = 0;
	int input_size = input.size();

	while (count < input_size){
		sample = input[count];
		new_couple = count_consecutive_terms(sample, input, count);
		count += new_couple[0];
		result_sequence.push_back(new_couple[0]);
		result_sequence.push_back(new_couple[1]);
	}

	return result_sequence;
}

vector<int> count_consecutive_terms(int sample, vector<int> input, int start_point){
	vector<int> couple(2);
	int next_term = sample;
	int count = 0;

	while (next_term == sample){
		count++;
		next_term = input[start_point + count];
	}

	couple[0] = count;
	couple[1] = sample;
	return couple;
}

void show_result(vector<int> result){
	int result_size = result.size();

	for (int i=0; i < result_size; i++){
		cout << result[i];
	}

	cout << endl;
}