#include <iostream>
#include <cmath>
#include <vector>
 using namespace std;

 double ask_for_height(void);
 double calc_mean(double, double, double);
 double calc_deviation(double, double, double, double);
 void show_result(double, double);
 void compare(vector<double>, double);
 void show_comparison(double, double);

 int main(){
 	double first_height;
 	double second_height;
 	double third_height;
 	double mean;
 	double standard_deviation;
 	vector<double> inputs;

 	first_height = ask_for_height();
 	second_height = ask_for_height();
 	third_height = ask_for_height();
 	inputs.push_back(first_height);
 	inputs.push_back(second_height);
 	inputs.push_back(third_height);

 	mean = calc_mean(first_height, second_height, third_height);
 	standard_deviation = calc_deviation(first_height, second_height, third_height, mean);

 	show_result(mean, standard_deviation);
 	compare(inputs, mean);
 	return 0;
 }

 double ask_for_height(){
 	double height;

 	cout << "Give me a height: ";
 	cin >> height;
 	cout << endl;

 	return height;
 }

 double calc_mean(double first, double second, double third){
 	double mean;

 	mean = (1/3.0) * (first + second + third);

 	return mean;
 }

 double calc_deviation(double first, double second, double third, double mean){
 	double deviation;
 	double first_diference;
 	double second_diference;
 	double third_diference;

 	first_diference = first - mean;
 	second_diference = second - mean;
 	third_diference = third - mean;

 	deviation = sqrt(
 					 (1/3.0) * ((first_diference * first_diference)
 							 + (second_diference * second_diference)
 							 + (third_diference * third_diference)));
 	
 	return deviation;
 }

 void show_result(double mean, double standard_deviation){
 	cout << "The average height is " << mean << endl;
 	cout << "and the standard deviation results in " << standard_deviation << endl;
 }

 void compare(vector<double> values, double mean){
 	for (int i = 0; i < values.size(); i++){
 		show_comparison(values[i], mean);
 	}
 }

 void show_comparison(double value, double mean){
 	if (value < mean){
 		cout << value <<" is lower than mean(" << mean <<")\n";
 	} else 
 	if (value > mean){
 		cout << value <<" is higher than mean(" << mean <<")\n";
 	} else {
 		cout << value <<" is the same as mean(" << mean <<")\n";
 	}
 }