#include <iostream>
#include <cstring>

//package abstract base class
class package{
	public:
		package();

		virtual ~package();

		virtual bool display() = 0;
		virtual int receive(const char*) = 0;
		virtual int send() = 0;
};

//delivery-type package
class delivery:public package{
	public:
		delivery();
		delivery(const delivery&);
		delivery(char* name, char* desti);
		~delivery();
		
		bool display(); //display package info 
		int receive(const char*); //accept package
		int send(); //send a package

	private:
		char* sender;
		char* address;
};

class in_delivery:public package{
	public:
		in_delivery();
		in_delivery(const in_delivery&);
		in_delivery(char* name, char* address, char* sign);
		~in_delivery();

		bool display(); //display package info 
		int receive(const char*); //accept package
		int send(); //send a package

	private:
		char* sender;
		char* address;
		char* signature;
};

class pickup:public package{
	public:
		pickup();
		pickup(const pickup&);
		pickup(char* name, char* address);
		~pickup();

		bool display(); //display package info 
		int receive(const char*); //accept package
		int send(); //send a package

	private:
		char* sender;
		char* address;
};

class in_pickup:public package{
	public:
		in_pickup();
		in_pickup(const in_pickup&);
		in_pickup(char* name, char* address, char* sign);
		~in_pickup();

		bool display(); //display package info 
		int receive(const char*); //accept package
		int send(); //send a package

	private:
		char* sender;
		char* address;
		char* signature;
};
