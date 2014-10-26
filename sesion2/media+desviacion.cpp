#include <iostream>
#include <cmath>
 using namespace std;

 double ask_for_height(void);
 double calc_mean(double, double, double);
 double calc_deviation(double, double, double, double);
 void show_result(double, double);

 int main(){
 	double first_height;
 	double second_height;
 	double third_height;
 	double mean;
 	double standard_deviation;

 	first_height = ask_for_height();
 	second_height = ask_for_height();
 	third_height = ask_for_height();

 	mean = calc_mean(first_height, second_height, third_height);
 	standard_deviation = calc_deviation(first_height, second_height, third_height, mean);

 	show_result(mean, standard_deviation);

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