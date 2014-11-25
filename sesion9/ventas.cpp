#include<iostream>
using namespace std;

class Sales{
	private:
		Office office_1;
		Office office_2;
		Office office_3;
		Product product_a;
		Product product_b;
		Product product_c;

	public:
		Sales(){
			office_1 = Office office('1');
			office_2 = Office office('2');
			office_3 = Office office('3');
			product_a = Product product('a');
			product_b = Product product('b');
			product_c = Product product('c');
		}

		void add_sale(int id_office, char id_product, int sales_number=1){};

		Office get_office(){};

		int get_winner(){};
};


int main(){
	Sales sales;
	cin >> indentif_sucursal;
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
		winner_id = sales.get_winner();
		winner_sales_number = sales.get_office(winner_id).get_sales_number();
	}
}