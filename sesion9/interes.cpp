#include<iostream>
using namespace std;

class Deposit{
	private:
		double capital;
		double interest;

		produced_capital_in_a_year(capital){
			return capital + (capital * interest / 100);
		}

	public:
		Deposit(_capital=0, _interest){
			capital = _capital;
			interest = _interest;
		}

		produced_capital(int years){
			double produced_capital = capital;

			for (int i=1; i <= years; i++){
				produced_capital += produced_capital_in_a_year(produced_capital);
			}

			return produced_capital;
		}

		years_to_double(){
			int years;
			double produced_capital = capital;

			for (years; produced_capital <= 2*capital; years++){
				produced_capital = produced_capital(years);
			}

			return years;
		}
};