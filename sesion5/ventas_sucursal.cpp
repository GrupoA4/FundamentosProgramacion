#include <iostream>
#include <vector>
using namespace std;

struct Code{
	int office_id;
	char product_id;
	int number_products;
};

vector<Code> ask_data(void);
bool check_code(Code);
int parse(vector<Code>);
void count_sales(Code, int*);
int compare_offices(int*);
void show_result(int);


int main(){
	vector<Code> codes;
	int best_office_id;

	codes = ask_data();
	best_office_id = parse(codes);

	show_result(best_office_id);
}

vector<Code> ask_data(){
	vector<Code> codes;
	Code code;
	bool ends;

	while (!ends){
		cout << "Enter a code\n";
		cin >> code.office_id;
		cin >> code.product_id;
		cin >> code.number_products;
		cout << endl;
		codes.push_back(code);
		ends = check_code(code);
	}

	return codes;
}

bool check_code(Code code){
	bool ends;

	ends = code.office_id == -1 || code.product_id == -1 || code.number_products == -1;

	return ends;
}

int parse(vector<Code> codes){
	int offices[3] = {};
	int best_office_id;

	for (int i=0; i<codes.size(); i++){
		count_sales(codes[i], offices);
	}

	best_office_id = compare_offices(offices);
}

void count_sales(Code code, int* offices){
	switch (code.office_id){
		case 1: offices[0] += code.number_products; break;
		case 2: offices[1] += code.number_products; break;
		case 3: offices[2] += code.number_products; break;
	}
}

int compare_offices(int* offices){
	int best_office_id;

	if (offices[0] > offices[1]){
		best_office_id = 1;
	} else {
		best_office_id = 2;
	}

	if (offices[2] > offices[best_office_id-1]){
		best_office_id = 3;
	}

	return best_office_id;
}

void show_result(int best_office_id){
	cout << "The office were more products has sold is " << best_office_id;
	cout << endl;
}