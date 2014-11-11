#include<iostream>
#include<vector>
using namespace std;

vector<int> ask_range(void);
vector<vector<int> > combine_ranges(vector<int>, vector<int>);
vector<int> range_to_set(vector<int>);
vector<vector<int> > combine_sets(vector<int>, vector<int>);
vector<vector<int> > combine_single_and_set(int, vector<int>);
void merge_sets(vector<vector<int> >*, vector<vector<int> >);
void show_result(vector<vector<int> >);
void show_pair(vector<int>);


int main(){
	vector<int> character_range_1(2);
	vector<int> character_range_2(2);
	vector<vector<int> > character_combinations;

	character_range_1 = ask_range();
	character_range_2 = ask_range();
	character_combinations = combine_ranges(character_range_1, character_range_2);

	show_result(character_combinations);
	return 0;
}

vector<int> ask_range(){
	vector<int> range(2);
	char min;
	char max;

	cout << "Enter a range defined by a minimum and a maximum:\n";
	cout << "Min: ";
	//No puedo asignar un char a un int?
	cin >> min;
	cout << "\nMax: ";
	cin >> max;
	cout << endl;

	range[0] = (int)min;
	range[1] = (int)max;

	return range;
}

vector<vector<int> > combine_ranges(vector<int> range_1, vector<int> range_2){
	vector<int> set_1;
	vector<int> set_2;
	vector<vector<int> > combined_set;

	set_1 = range_to_set(range_1);
	set_2 = range_to_set(range_2);
	combined_set = combine_sets(set_1, set_2);

	return combined_set;
}

vector<int> range_to_set(vector<int> range){
	vector<int> set;

	for (int i=range[0]; i <= range[1]; i++){
		set.push_back(i);
	}

	return set;
}

vector<vector<int> > combine_sets(vector<int> set_1, vector<int> set_2){
	vector<vector<int> > combined_set;
	vector<vector<int> > same_head_pairs;
	vector<int> pair(2);

	for (int i=0; i < set_1.size(); i++){
		same_head_pairs = combine_single_and_set(set_1[i], set_2);
		merge_sets(&combined_set, same_head_pairs);
	}

	return combined_set;
}

vector<vector<int> > combine_single_and_set(int single, vector<int> set){
	vector<int> pair(2);
	vector<vector<int> > combined_pairs;

	pair[0] = single;
	for (int i=0; i < set.size(); i++){
		pair[1] = set[i];
		combined_pairs.push_back(pair);
	}

	return combined_pairs;
}

void merge_sets(vector<vector<int> > *container_set, vector<vector<int> > to_merge_set){

	for (int i=0; i < to_merge_set.size(); i++){
		container_set->push_back(to_merge_set[i]);
	}
}

void show_result(vector<vector<int> > combinations){

	cout << "Mixing the sets... the result is:\n";
	for (int i=0; i < combinations.size(); i++){
		show_pair(combinations[i]);
	}
	cout << endl;
}

void show_pair(vector<int> pair){

	for (int i=0; i<2; i++){
		cout << (char)pair[i];
	}
	cout << ", ";
}