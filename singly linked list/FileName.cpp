#include<iostream>
using namespace std;
class node {
private:
	
	node* next_node;//stores the address of next node
	int data;
	friend class list;
public:
	
	node(int new_data=0,node*next=nullptr) {
		data = new_data;
		next_node = next;
	}
	void setnext(node *n) {
		next_node = n;

	}
	node *getnext() {
		return next_node;
	}
	int getdata() {
		return data;
	}


};
class list {
private:
	node* listhead;
	int size;
public:
	list() {
		listhead = nullptr;
		size = 0;	
	}
	//now making getters and setters
	node* gethead(){
		return listhead;
	}
	int getsize() {
		return size;
	}
	bool isempty() {
		if (listhead == nullptr) {
			return true;
		}
		else return false;
	}
	void pushfront(int value) {
	
		node* newnode = new node(value, listhead);
		listhead = newnode;
		size++;
		
		

	}
	
	void display() {
		for (node* ptr = listhead; ptr != nullptr; ptr = ptr->next_node) {
			cout << ptr->data << " ";
		}
		cout << "NULL";
	}
	int front()const {//accessing the first element of the list
		if (listhead != nullptr) {
			return listhead->data;
		}
	}
	int popfront() {
		if (isempty()) {
			cout<<"cant delete from an empty list";
			//underflow is when we are trying to delete something that is already empty
			return -1;
		}
		int e = front();
		node* ptr = listhead;
		listhead = listhead->next_node;
		delete ptr;
		size--;
		return e;


	}
	int end() {
		int end ;
		for (node* ptr = listhead; ptr != nullptr; ptr = ptr->getnext()) {
			if (ptr->getnext() == nullptr) {
				end = ptr->getdata();
			}

		}
		return end;
	}


	int count(int n) {
		int nodecount = 0;
		for (node* ptr = listhead; ptr != nullptr; ptr = ptr->getnext()) {
			if (ptr->getdata() == n) {
				nodecount++;
			}
			
		}
		return nodecount;
	}
	//adding a new element at the end of the list
	void pushend(int n) {
		node* newnode = new node(n, nullptr);
		if (isempty()) {
			listhead = newnode;
			size++;
			return;
		}
		node* last = nullptr;
		for (node* ptr = listhead; ptr != nullptr; ptr = ptr->getnext()) {
			last = ptr;
		}
		
		last->setnext(newnode);
		size++;
	}
	int popend() {
		if (listhead == nullptr) {
			cout << "the list is empty" << endl;
			return -1;
		}
		//if the list has only node
		int e;
		if (listhead->next_node == nullptr) {
			e = listhead->getdata();
			delete listhead;
			return e;

		}
		
		node* last = listhead;
		node* ptr;
		for (ptr = listhead; ptr->next_node != nullptr; ptr = ptr->next_node) {

			last = ptr;//storess the previous node

		}
		int deleted = ptr->getdata();
		last->setnext(nullptr);
		delete ptr;
		size--;
		return deleted;
		
	}
	void erase(int n) {
		//if the list is empty
		if (isempty()) {
			cout << "the list is emptry";
			return;
		}

		//delete from the front or end
	
		if(listhead->getdata() == n and !isempty()) {
			node* temp = listhead;
		
			listhead = listhead->next_node;
			delete temp;
		

	
		}
		if (isempty()) {
			return;//if the list become empty stop!!!!
		}
		
		node*prev= listhead;
		node* current= listhead->getnext();

		while (current!=nullptr) {//looping to the end of list
			if (current->getdata() == n) {
				prev->setnext(current->getnext());//assigning address
				
				prev = current->getnext();//assigning value
				delete current;
				size--;
				return;
			}
			
			
			prev = current;//first to second -second to next
			current = current->getnext();


			

		}


		
		

	}


		
	
};
int main() {
	list mylist;
	
	mylist.pushend(345);
	mylist.pushend(234);
	mylist.pushend(345);
	mylist.erase(345);
	
	////mylist.display();
	//cout << endl;
	//cout<<"the size of my list is equal to:"<<" "<<mylist.getsize();
	//cout << endl;
	//cout<<mylist.front();
	//cout << endl;
	//cout<<"removing element from the very start:"<<" "<<mylist.popfront();
	//cout << endl;
	//mylist.display();
	//cout << endl;
	//cout << "DISPLAYING THE COUNT OF NUMBERS IN THE LIST"<<endl;
	//cout<<mylist.count(24)<<endl;
	//cout << "showing the last elemnt of the list" << endl;
	//cout << mylist.end()<<endl;
	//cout << "adding a newnode at the end" << endl;
 //   mylist.pushend(345);
	//mylist.display();
	//cout << endl;
	//cout << "popping from the end" << endl;
	//cout<<mylist.popend()<<endl;
	mylist.display();


	return 0;


}
