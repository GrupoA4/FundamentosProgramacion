#include<iostream>
using namespace std;

class Office{
	private:
		int id;
		int sales_number;

	public:
		Office(int _id){
			id = _id;
			sales_number = 0;
		}

		Office(){
			sales_number = 0;
		}

		void set_id(int _id){
			id = _id;
		}

		void add_sale(char id_product, int _sales_number=1){
			sales_number += _sales_number;
		}

		int get_sales_number(){
			return sales_number;
		}

		int get_id(){
			return id;
		}
};

class Product{
	private:
		char id;

	public:
		Product(char _id){
			id = _id;
		}
};

class Sales{
	private:
		Office office_1;
		Office office_2;
		Office office_3;

	public:
		Sales(){
			office_1.set_id(1);
			office_2.set_id(2);
			office_3.set_id(3);
		}

		void add_sale(int id_office, char id_product, int sales_number=1){
			Office office = get_office(id_office);

			office.add_sale(id_product, sales_number);
		};

		Office get_office(int id){
			Office office(1);

			if (id == 1){
				office = office_1;
			} else if (id == 2){
				office = office_2;
			} else {
				office = office_3;
			}

			return office;
		};

		Office get_winner(){
			Office office_winner(1);

			if (office_1.get_sales_number() > office_2.get_sales_number()){
				Office office_winner = office_1;
			} else {
				Office office_winner = office_2;
			}

			if (office_3.get_sales_number() > office_winner.get_sales_number()){
				office_winner = office_3;
			}

			return office_winner;
		};
};


int main(){
	Sales sales;
	const int TERMINADOR = -1;
	int identif_sucursal;
	bool fichero_vacio;
	char cod_producto;
	int unidades_vendidas;

	cin >> identif_sucursal;
	fichero_vacio = identif_sucursal == TERMINADOR;

	if (!fichero_vacio){
		while (identif_sucursal != TERMINADOR){
			cin >> cod_producto;
			cin >> unidades_vendidas;

			sales.add_sale(identif_sucursal, cod_producto, unidades_vendidas);

			cin >> identif_sucursal;
		}

		int winner_id;
		int winner_sales_number;
		Office winner_office = sales.get_winner();
		winner_id = winner_office.get_id();
		winner_sales_number = sales.get_office(winner_id).get_sales_number();

		cout << winner_id << " " << winner_sales_number;
	}
}