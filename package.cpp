#include "package.h"
using namespace std;

//package class
package::package(){};
package::~package(){}


//delivery class
delivery::delivery():sender(NULL),address(NULL){}
delivery::delivery(const delivery& source){
	sender = new char[strlen(source.sender)+1];
	strcpy(sender, source.sender);

	address = new char[strlen(source.address)+1];
	strcpy(address, source.address);
}
delivery::delivery(char* name, char* desti){
	sender = new char[strlen(name)+1];
	strcpy(sender, name);

	address = new char[strlen(desti)+1];
	strcpy(address, desti);
}
//display package information
bool delivery::display(){
	if(!sender) return false; //no information contained
	//display info
	cout << "\nSender: " << sender
		<< "\nFrom: " << address << endl;
	return true;
}
//check given info to retrieve package
int delivery::receive(const char* name){
	if(strcmp(name, sender) != 0) return 0; //name not matching
	else return 1; //matching info found
}
//give information to send package
int delivery::send(){
	cout << "\nEnter sender's name: ";
	cin.get(sender, 20, '\n'); cin.ignore(100, '\n');

	cout << "\nEnter sender's address: ";
	cin.get(address, 50, '\n'); cin.ignore(100, '\n');
	return 0;
}
delivery::~delivery(){
	delete [] sender;
	delete [] address;
}


//insured delivery class
in_delivery::in_delivery():sender(NULL),address(NULL),signature(NULL){}
in_delivery::in_delivery(const in_delivery& source){
	sender = new char[strlen(source.sender)+1];
	strcpy(sender, source.sender);

	address = new char[strlen(source.address)+1];
	strcpy(address, source.address);

	signature = new char[strlen(source.signature)+1];
	strcpy(signature, source.signature);
}
in_delivery::in_delivery(char* name, char* desti, char* sign){
	sender = new char[strlen(name)+1];
	strcpy(sender, name);

	address = new char[strlen(desti)+1];
	strcpy(address, desti);

	signature = new char[strlen(sign)+1];
	strcpy(signature, sign);
}
//display package information
bool in_delivery::display(){
	if(!sender) return false; //no info contained
	//display info
	cout << "\nSender: " << sender
		<< "\nFrom: " << address
		<< "\nSignature: " << signature << endl;
	return true;
}
//receive package
int in_delivery::receive(const char* name){
	if(strcmp(name, sender) != 0) return 0; //name not matching package info

	//ask user to enter required signature
	char a_signature[50];
	cout << "\nThe package requires a signature: ";
	cin.get(a_signature, 50, '\n'); cin.ignore(100, '\n');

	if(strcmp(a_signature, signature) != 0) return 0; //signature not matching
	else return 1; //receive package
}
//input required package info
int in_delivery::send(){
	cout << "\nEnter sender's name: ";
	cin.get(sender, 20, '\n'); cin.ignore(100, '\n');

	cout << "\nEnter sender's address: ";
	cin.get(address, 50, '\n'); cin.ignore(100, '\n');

	cout << "\nEnter required signature: ";
	cin.get(signature, 50, '\n'); cin.ignore(100, '\n');
	return 0;
}
in_delivery::~in_delivery(){
	delete [] sender;
	delete [] address;
	delete [] signature;
}


//pickup class
pickup::pickup():sender(NULL),address(NULL){}
pickup::pickup(const pickup& source){
	sender = new char[strlen(source.sender)+1];
	strcpy(sender, source.sender);

	address = new char[strlen(source.address)+1];
	strcpy(address, source.address);
}
pickup::pickup(char* name, char* desti){
	sender = new char[strlen(name)+1];
	strcpy(sender, name);

	address = new char[strlen(desti)+1];
	strcpy(address, desti);
}
//display package info
bool pickup::display(){
	if(!sender) return false; //no info contained
	//display contained info
	cout << "\nSender: " << sender
		<< "\nFrom: " << address << endl;
	return true;
}
//receive package
int pickup::receive(const char* name){
	if(strcmp(name, sender) != 0) return 0; //name does not match package info
	else return 1; //name matches, retrieve package
}
//provide sender info of package
int pickup::send(){
	cout << "\nEnter sender's name: ";
	cin.get(sender, 20, '\n'); cin.ignore(100, '\n');

	cout << "\nEnter sender's address: ";
	cin.get(address, 50, '\n'); cin.ignore(100, '\n');
	return 0;
}
pickup::~pickup(){
	delete [] sender;
	delete [] address;
}


//insured pickup class
in_pickup::in_pickup():sender(NULL),address(NULL),signature(NULL){}
in_pickup::in_pickup(const in_pickup& source){
	sender = new char[strlen(source.sender)+1];
	strcpy(sender, source.sender);

	address = new char[strlen(source.address)+1];
	strcpy(address, source.address);

	signature = new char[strlen(source.signature)+1];
	strcpy(signature, source.signature);
}
in_pickup::in_pickup(char* name, char* desti, char* sign){
	sender = new char[strlen(name)+1];
	strcpy(sender, name);

	address = new char[strlen(desti)+1];
	strcpy(address, desti);

	signature = new char[strlen(sign)+1];
	strcpy(signature, sign);
}
//display package info
bool in_pickup::display(){ 
	if(!sender) return false; //no info contained
	//display info
	cout << "\nSender: " << sender
		<< "\nFrom: " << address
		<< "\nSignature: " << signature << endl;
	return true;
}
//receive package
int in_pickup::receive(const char* name){
	if(strcmp(name, sender) != 0) return 0; //package info not matching

	//ask for required signature
	char a_signature[50];
	cout << "\nThe package requires a signature: ";
	cin.get(a_signature, 50, '\n'); cin.ignore(100, '\n');

	if(strcmp(a_signature, signature) != 0) return 0; //signature doesn't match contained one
	else return 1; //retrieve package
}
//provide sender information
int in_pickup::send(){
	cout << "\nEnter sender's name: ";
	cin.get(sender, 20, '\n'); cin.ignore(100, '\n');

	cout << "\nEnter sender's address: ";
	cin.get(address, 50, '\n'); cin.ignore(100, '\n');

	cout << "\nEnter signature required: ";
	cin.get(signature, 50, '\n'); cin.ignore(100, '\n');
	return 0;
}
in_pickup::~in_pickup(){
	delete [] sender;
	delete [] address;
	delete [] signature;
}
