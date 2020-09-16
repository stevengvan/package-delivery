#include "package.h"

//hold of package informations
class node{
	public:
		node();
		node(package*, char* name, char* desti, char* desc);
		node(const node*&);
		~node();

		int display_item(); //display package info of package
		int display(node* curr); //display all packages (wrapper)
		int insert(node*& front, node*& add); //connect a new package (wrapper)
		int find_item(node*, const char*); //find a package matching receiver (wrapper)
		int delete_item(node*& curr, const char*); //delete item in route
		void route_deletion(node*& front, node*& end); //wrapper to delete_connection

	private:
		int delete_connection(node*& front); //deallocation for route class

		package * item;
		char* receiver;
		char* r_address;
		char* content;
		node* next;
};

//list of packages
class route{
	public:
		route();
		route(const node&);
		~route();

		int insert(const node*); //add a package to the route
		int retrieve(const char*); //find a package matching the receiver
		int delete_delivery(const char*); //delete a package from the route
		int display_route(); //display the route for packages
		void delete_routes(); //deallocate route list
	
	private:
		node * front;
		node* rear;
};
