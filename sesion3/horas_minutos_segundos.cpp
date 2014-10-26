#include <iostream>
using namespace std;

struct Time{
	int hours;
	int mins;
	int seconds;
};

int ask_for_hours(void);
int ask_for_mins(void);
int ask_for_seconds(void);
void normalize(Time*);
void show_result(Time);

int main(){
	Time my_time;
	int *result;

	my_time.hours = ask_for_hours();
	my_time.mins = ask_for_mins();
	my_time.seconds = ask_for_seconds();

	normalize(&my_time);
	show_result(my_time);
	return 0;
}

int ask_for_hours(){
	int hours;

	cout << "How many hours do you want pass me?\n >  ";
	cin >> hours;
	cout << endl;

	return hours;
}

int ask_for_mins(){
	int mins;

	cout << "Would you like add some minutes?\n >  ";
	cin >> mins;
	cout << endl;

	return mins;
}

int ask_for_seconds(){
	int seconds;

	cout << "And seconds?\n >  ";
	cin >> seconds;
	cout << endl;

	return seconds;
}

void normalize(Time *tim){
	int temp_mins = tim->mins;
	int temp_seconds = tim->seconds;

	tim->seconds = tim->seconds % 60;
	temp_mins = tim->mins + (temp_seconds / 60);
	tim->mins = temp_mins % 60;
	tim->hours = tim->hours + (temp_mins / 60);
}

void show_result(Time tim){
	cout << "The correct hour is -> ";
	cout << tim.hours << ":";
	cout << tim.mins << ":";
	cout << tim.seconds << endl;
}