//This program will be a package
//delivery service where we can
//request different type of package
//deliveries.

#include "node.h"
using namespace std;

int give_choice(); //menu of packages
void get_receiver(char* name, char* address, char* description); //get receiver info
void get_sender(char* name, char* address); //get sender info
void receive_package(char* name, package* match);
void test(); //test class functions
int main(){
	//test functions;
	//test();

	//route
	route list;

	//sending a package
	bool start = true;
	do{
		char s_name[20];
		char r_name[20];
		char s_address[50];
		char r_address[50];
		char description[100];

		//select delivery options	
		int choice = give_choice();

		package* a_item; //package (only sender)
		node* to_add; //entire package

		//get sender info
		get_sender(s_name, s_address);

		//delivery service
		if(choice == 1){
			//supply package info
			a_item = new delivery(s_name, s_address);
			get_receiver(r_name, r_address, description);
			to_add = new node(a_item, r_name, r_address, description);
		}

		//insured delivery service
		if(choice == 2){
			//provide signature for receiver
			char signature[20];
			cout << "\nEnter a signature required for receiver: ";
			cin.get(signature, 20, '\n'); cin.ignore(100, '\n');

			//supply package info
			a_item = new in_delivery(s_name, s_address, signature);
			get_receiver(r_name, r_address, description);
			to_add = new node(a_item, r_name, r_address, description);
		}

		//package pickup service
		if(choice == 3){
			//supply package info
			a_item = new pickup(s_name, s_address);
			get_receiver(r_name, r_address, description);
			to_add = new node(a_item, r_name, r_address, description);
		}

		//insured package pickup service
		if(choice == 4){
			//provide signature for receiver
			char signature[20];
			cout << "\nEnter a signature required for receiver: ";
			cin.get(signature, 20, '\n'); cin.ignore(100, '\n');

			//supply package info
			a_item = new in_pickup(s_name, s_address, signature);
			get_receiver(r_name, r_address, description);
			to_add = new node(a_item, r_name, r_address, description);
		}

		//ask to receive or add to route
		char decision;
		cout << "\nDo you want to receive the package (y/n): ";
		cin >> decision; cin.ignore(100, '\n');

		//add package to list
		if(decision == 'n'){
			cout << "\nAdded to route";
			list.insert(to_add);
		}

		//display package and not add to route
		else receive_package(s_name, a_item);

		delete to_add;

		cout << "\nDo you want to add another package (y/n): ";
		cin >> decision; cin.ignore(100, '\n');
		if(decision == 'n') start = false;	
	} while(start); //continue adding packages

	//display route
	cout << "\nRoutes:\n";
	if(list.display_route())
		cout << "\nNo routes\n";
	return 0;
}

//get choice for delivery
int give_choice(){
	int choice = 0;
	cout << "\nWhat kind of delivery is it:"
		<< "\n1) Delivery"
		<< "\n2) Insured Delivery"
		<< "\n3) Package Pickup"
		<< "\n4) Insured Package Pickup"
		<< "\n\nChoice: ";
	cin >> choice; cin.ignore(100, '\n');
	return choice;
}
//Get receiver
void get_receiver(char* name, char* address, char* description){
	cout << "\nEnter the receiver: ";
	cin.get(name, 20, '\n'); cin.ignore(100, '\n');

	cout << "\nEnter receiver's address: ";
	cin.get(address, 50, '\n'); cin.ignore(100, '\n');

	cout << "\nWhat's in the package:\n";
	cin.get(description, 100, '\n'); cin.ignore(100, '\n');
}

//Get sender information
void get_sender(char* name, char* address){
	cout << "\nEnter the sender: ";
	cin.get(name, 20, '\n'); cin.ignore(100, '\n');

	cout << "\nEnter sender's address: ";
	cin.get(address, 50, '\n'); cin.ignore(100, '\n');
}

//receive package
void receive_package(char* name, package* match){
	delivery* ptr = dynamic_cast<delivery*>(match);
	if(ptr){
		if(ptr->receive(name) == 1) cout << "\nReceived Package";}
	else{
		in_delivery* ptr = dynamic_cast<in_delivery*>(match);
		if(ptr){
			if(ptr->receive(name) == 1) cout << "\nReceived Package";}
		else{
			pickup* ptr = dynamic_cast<pickup*>(match);
			if(ptr){
				if(ptr->receive(name) == 1) cout << "\nReceived Package";}
			else{
				in_pickup* ptr = dynamic_cast<in_pickup*>(match);
				if(ptr){
					if(ptr->receive(name) == 1) cout << "\nReceived Package";}
				else cout << "\nError in receiving package";
			}
		}
	}
}
//test class functions
void test(){
	delivery a_package("Stan", "123 Sesame St.");
	in_delivery a_package2("Trample", "234 Dan St.", "Wook");
	pickup a_package3("Wookie", "543  Work St.");
	in_pickup a_package4("Mitch", "Shorty St.", "Try");
	package * the_package = &a_package;
	package * the_package2 = &a_package2;
	package * the_package3 = &a_package3;
	package * the_package4 = &a_package4;
	node * temp = new node(the_package, "Riddley", "444 stret", "USB drive");
	node * temp2 = new node(the_package2, "Armin", "92340", "Cube");
	node * temp3 = new node(the_package3, "Lindle", "91231", "Under");
	node * temp4 = new node(the_package4, "Wik", "31", "Beneath");

	route list;
	list.insert(temp);
	list.insert(temp2);
	list.insert(temp3);
	list.insert(temp4);
	delete temp;
	delete temp2;
	delete temp3;
	delete temp4;

	//list.display_route();
	//list.delete_delivery("Lindle");
	//list.retrieve("Armin");
	list.display_route();
}
