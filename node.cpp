#include "node.h"
using namespace std;

//node class
node::node():item(NULL),receiver(NULL),r_address(NULL),content(NULL){}
node::node(package* source, char* name, char* desti, char* desc){
	if(source) item = source;

	receiver = new char[strlen(name)+1];
	strcpy(receiver, name);

	r_address = new char[strlen(desti)+1];
	strcpy(r_address, desti);

	content = new char[strlen(desc)+1];
	strcpy(content, desc);
}
node::node(const node*& source){
	if(source->item) item = source->item;

	receiver = new char[strlen(source->receiver)+1];
	strcpy(receiver, source->receiver);

	r_address = new char[strlen(source->r_address)+1];
	strcpy(r_address, source->r_address);

	content = new char[strlen(source->content)+1];
	strcpy(content, source->content);
}
//display additional package information
int node::display_item(){
	cout << "\nTo: " << receiver
		<< "\nSend to: " << r_address
		<< "\nContent: " << content << endl;
	
	//downcast to display correct sender information
	if(item){
		delivery * ptr = dynamic_cast<delivery*>(item);
		if(ptr) ptr->display();
		else{
			in_delivery * ptr = dynamic_cast<in_delivery*>(item);
			if(ptr) ptr->display();
			else {
				pickup * ptr = dynamic_cast<pickup*>(item);
				if(ptr) ptr->display();
				else{
					in_pickup * ptr = dynamic_cast<in_pickup*>(item);
					if(ptr) ptr->display();
					else return 0;
				}
			}
		}
	}
	return 1;
}
//connect a node to another
int node::insert(node*& front, node*& add){
	add->next = front; 
	this->next = add;
	front = add;
	return 0;
}
//find matching package
int node::find_item(node* curr, const char* find){
	if(strcmp(curr->receiver, find) == 0){
		curr->display_item();
		return 1;
	}
	if(curr == this) return 0;
	return find_item(curr->next, find);
}
//delete package for route
int node::delete_item(node*& curr, const char* find){
	//one package in list only 
	if(strcmp(curr->receiver, find) == 0){
		node* temp = curr;
		delete temp;
		temp = NULL;
		return 1;
	}
	//multiple packages in list
	if(strcmp(curr->next->receiver, find) == 0){
		node* temp = curr->next;
		curr->next = temp->next;
		delete temp;
		temp = NULL;
		return 1;
	}
	//package not found
	if(curr->next == this) return 0;
	return delete_item(curr->next, find); //recursive call
}
//display entire node conneciton (wrapper)
int node::display(node* curr){
	if(!curr) return 0; //no node exists

	//reached last item
	if(curr == this){
		curr->display_item();
		return 1;
	}
	curr->display_item(); //display current node info
	return display(curr->next); //recursive call to next node;
}
//wrapper function to delete conneciton of packages
void node::route_deletion(node*& front, node*& end){
	if(!end || !front) return;
	node*temp = NULL;
	end->next = temp;
	delete_connection(front);
}
//recursive function to delete packages and its connection
int node::delete_connection(node*& front){
	if(!front) return 0;
	delete_connection(front->next);
	delete front;
	return 1;
}
node::~node(){
	delete [] receiver;
	receiver = NULL;
	delete [] r_address;
	r_address = NULL;
	delete [] content;
	content = NULL;
}


//route class
route::route(){
	rear = front = NULL;
}
//insert a package to route
int route::insert(const node* to_add){
	//no package exists
	if(!rear){
		rear = new node(to_add);
		node * temp = rear;
		rear->insert(front, temp);
		return 0;
	}
	//add a package to existing list
	node * temp = new node(to_add);
	rear->insert(front, temp);
	return 0;
}
//find a package within route
int route::retrieve(const char* find){
	if(!rear) return 0; //no route exists
	return rear->find_item(front, find); //call recursive function
}
//delete a package within route
int route::delete_delivery(const char* find){
	if(!rear) return 0; //no route exists
	rear->delete_item(rear, find); //call recursive function
	return 1;
}
//display route
int route::display_route(){
	if(!rear) return 0; //route does not exist
	rear->display(front); //call recursive function
	return 1;
}
//deallocation function for route
void route::delete_routes(){
	//call for wrapper function in node class
	rear->route_deletion(front, rear);
}
route::~route(){
	delete_routes();
}

