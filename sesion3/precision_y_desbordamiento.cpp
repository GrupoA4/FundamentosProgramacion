#include <iostream>
using namespace std;

void test_a(void);
void test_b(void);
void test_c(void);
void test_d(void);
void test_e(void);
void test_f(void);
void test_g(void);
void show_result(int);
void show_result(long);
void show_result(double);
void show_result(float);
void show_real_result(unsigned long long);
void show_real_result(long double);

int main(){

	test_a();
	test_b();
	test_c();
	test_d();
	test_e();
	test_f();
	test_g();

	return 0;
}

void show_result(int result){
	cout << "The result of the test is: " << result << "\n";
}
void show_result(long result){
	cout << "The result of the test is: " << result << "\n";
}
void show_result(float result){
	cout << "The result of the test is: " << result << "\n";
}
void show_result(double result){
	cout << "The result of the test is: " << result << "\n";
}

void show_real_result(unsigned long long result){
	cout << "Result should be: " << result << endl;
}
void show_real_result(long double result){
	cout << "Result should be: " << result << endl;
}


void test_a(){
	int chico, chico1, chico2;
	unsigned long long control;

	chico1 = 123456789;
	chico2 = 123456780;
	chico = chico1 * chico2;
	control = chico1 * chico2;

	cout << "TEST A:\n";
	show_result(chico);
	show_real_result(control);
}

void test_b(){
	long grande;
	int chico1, chico2;
	unsigned long long control;

	chico1 = 123456789;
	chico2 = 123456780;
	grande = chico1 * chico2;
	control = chico1 * chico2;

	cout << "TEST B:\n";
	show_result(grande);
	show_real_result(control);
}

void test_c(){
	double resultado, real1, real2;
	long double control;

	real1 = 123.1;
	real2 = 124.2;
	resultado = real1 * real2;
	control = real1 * real2;

	cout << "TEST C:\n";
	show_result(resultado);
	show_real_result(control);
}

void test_d(){
	double resultado, real1, real2;
	long double control;

	real1 = 123456789.1;
	real2 = 123456789.2;
	resultado = real1 * real2;
	control = real1 * real2;

	cout << "TEST D:\n";
	show_result(resultado);
	show_real_result(control);
}

void test_e(){
	double real, otro_real;
	long double control;

	real = 2e34;
	otro_real = real + 1;
	otro_real = otro_real - real;
	control = (real + 1) - real;

	cout << "TEST E:\n";
	show_result(otro_real);
	show_real_result(control);
}

void test_f(){
	double real, otro_real;
	long double control;

	real = 1e+300;
	otro_real = 1e+200;
	otro_real = otro_real * real;
	control = otro_real * real;

	cout << "TEST F:\n";
	show_result(otro_real);
	show_real_result(control);
}

void test_g(){
	float chico;
	double grande;
	long double control;

	grande = 2e+150;
	chico = grande;
	control = 2e+150;

	cout << "TEST G:\n";
	show_result(chico);
	show_real_result(control);
}

