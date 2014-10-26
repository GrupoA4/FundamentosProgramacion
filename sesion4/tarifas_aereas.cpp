#include <iostream>
using namespace std;

struct Ticket{
	double price;
	double distance;
};

struct Client{
	bool is_previous;
	Ticket ticket;
};

bool ask_is_previous(void);
bool check_response(char);
double ask_for_distance(void);
double calc_price(Ticket);
double add_offerts_additional(Client);
double add_offerts_exclusive(Client);
void add_offert_a(Client*);
void add_offert_b(Client*);
void add_offert_c(Client*);
void show_result(Client);

int main(){
	Client client;

	client.is_previous = ask_is_previous();
	client.ticket.distance = ask_for_distance();
	client.ticket.price = calc_price(client.ticket);
	//Para el profesor: cambia al otro modo de ofertas
	//con la funcion add_offerts_exclusive(client)
	client.ticket.price = add_offerts_exclusive(client);

	show_result(client);
	return 0;
}

bool ask_is_previous(){
	char response;
	bool is_previous;

	cout << "You have travelled with us before? y/n\n >  ";
	cin >> response;
	cout << endl;

	is_previous = check_response(response);

	return is_previous;
}

bool check_response(char response){
	bool result;

	if (response == 'y' || response == 'Y'){
		result = true;
	} else
	if (response == 'n' || response == 'N'){
		result = false;
	} else {
		result = false;
	}

	return result;
}

double ask_for_distance(){
	double distance;

	cout << "How many kilometers will take the travel?\n >  ";
	cin >> distance;
	cout << endl;

	return distance;
}

double calc_price(Ticket ticket){
	const int BASE_PRICE = 150;
	ticket.price = BASE_PRICE;

	if (ticket.distance > 200){
		ticket.price += (ticket.distance - 200) * 0.1;
	}

	return ticket.price;
}

double add_offerts_additional(Client client){
	add_offert_a(&client);
	add_offert_b(&client);
	add_offert_c(&client);

	return client.ticket.price;
}

double add_offerts_exclusive(Client client){

	if (client.is_previous){
		add_offert_c(&client);
	} else{
		add_offert_a(&client);
		add_offert_b(&client);
	}

	return client.ticket.price;
}

void add_offert_a(Client *client){
	double distance = client->ticket.distance;
	const bool IS_VALID = distance > 600 && distance <= 1100;

	if (IS_VALID){
		client->ticket.price -= client->ticket.price * 0.03;
	}
}

void add_offert_b(Client *client){
	double distance = client->ticket.distance;
	const bool IS_VALID = distance > 100;

	if (IS_VALID){
		client->ticket.price -= client->ticket.price * 0.04;
	}
}

void add_offert_c(Client *client){
	const bool IS_VALID = client->is_previous;

	if (IS_VALID){
		client->ticket.price -= client->ticket.price * 0.05;
	}
}

void show_result(Client client){
	cout << "Calculating...  The final price is ";
	cout << client.ticket.price;
	cout << endl;
}