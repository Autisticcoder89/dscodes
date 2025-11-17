#include<iostream>
using namespace std;


//implementing doubly linked list
class node {
private:
	int element;
	node* next;
	node* prev;
public:
	//parameterized constructor
	//setters
	node(int i, node* pre, node* nex):element(i),prev(pre),next(nex){

	}
	void setnext(node*n) {
		next=n;
	}
	void setprev(node* n) {
		prev=n;
	}
	void setelement(int n) {
		element = n;
	}
	//getters
	int retrieve()const {
		return element;
	}
	node* getnext() const{
		return  next;
	}
	node* getprev() {
		return prev;
	}


};
class doublylinkedlist {
private:
	node* listhead;
	node* listtail;
	
	
	int size = 0;
public:
	~doublylinkedlist();
	doublylinkedlist() {
		listhead = nullptr;
		listtail = nullptr;
	}
	bool isempty()const {
		if (listhead == nullptr) {
			return true;
		}
		else return false;
	}
	int getsize() {
		return size;
	}
	int count(int n)const {
		int nodecount = 0;
		for (node* ptr = listhead; ptr != nullptr; ptr = ptr->getnext()) {
			if (ptr->retrieve() == n) {
				nodecount++;
			}
		}
		return nodecount;
	}
	int front() const{
		if (listhead!=nullptr) {
			return listhead->retrieve();
		}
	}
	int end() const{
		node* ptr;
		if (listhead==nullptr) {
			cout << "the list is empty";
			return -1;
		}
	
		for (ptr = listhead;  ptr != nullptr&& ptr->getnext()!=nullptr;) {
			ptr = ptr->getnext();

		}
		int end = ptr->retrieve();
		return end;

	}
	void display() {
		for (node*ptr = listhead; ptr != nullptr; ptr = ptr->getnext()) {
			cout << ptr->retrieve()<<" ";
			
		}
		cout << "null";
	}
	void pushfront(int n) {
		node* temp = new node(n,nullptr,nullptr);
		if (listhead == nullptr) {
			listhead = temp;
		
		}
		else {
			//case for one  node or more then one node
			temp->setnext(listhead);
			listhead->setprev(temp);//there can be a forward longer list which we dont know about
			listhead = temp;
	
		}
		size++;
	}
	void pushback(int n) {
		node* temp = new node(n, nullptr, nullptr);
		if (listhead == nullptr) {
			listhead = temp;
			listtail = temp;
		}
		else {
			node* last = nullptr;
			node* ptr;
			for ( ptr = listhead; ptr!= nullptr; ptr = ptr->getnext()) {
				last= ptr;
			}
			temp->setprev(last);
			last->setnext(temp);
			//no use of pointing it to null

		}
		size++;
	}
	int popfront() {
		if (listhead == nullptr) {
			cout << "you cant pop a list that's already empty";
		}// has one node implementation too in notes
		else {
			int e = front();
			node* ptr = listhead;
			listhead->getnext()->setprev(nullptr);
			listhead = listhead->getnext();
			delete ptr;
			return e;
		}
	}
	int popend() {
		if (listhead == nullptr) {
			cout << "you cant pop a list that's already empty";
		}
		if (listhead->getnext() == nullptr) {
			int e = listhead->retrieve();
			node* ptr = listhead;

			delete ptr;
			listhead = nullptr;
			return e;
		}

		node* last=nullptr;
		for (node*ptr = listhead; ptr != nullptr; ptr = ptr->getnext()) {
			last = ptr;
		}
		node* ptr = last;
		int e = last->retrieve();
		node* newtail = last->getprev();
		newtail->setnext(nullptr);
		delete ptr;
		size--;
		return e;
		

	}
	int erase(int n) {
		if (isempty()) {
			cout << "empty list";
			return -1;
		}
		//if n is at the front

		while (listhead &&listhead->retrieve()==n) {
			node* temp = listhead;
			node* newhead = listhead->getnext();
			if(newhead)newhead->setprev(nullptr);
			listhead = newhead;
			delete temp;
			size--;
		
		}
		
		node* prev = listhead;
		//can be null too
		node* current;
		if (listhead != nullptr) {
			current = listhead->getnext();

		}
		else {
			current = nullptr;
		}
		while (current != nullptr) {
			if (current->retrieve() == n) {
				node* temp = current->getnext();
				prev->setnext(temp);
				if(temp)temp->setprev(prev);
				delete current;
			
				current = temp;///now the connection established will be current
				size--;

			}
			else {
				prev = current;
				current = current->getnext();
			}
		}
		
		
		
	}
	
	
		
	

};
doublylinkedlist::~doublylinkedlist() {
	node* current = listhead;
	while (current != nullptr) {
		node* next = current->getnext();
		delete current;
		current = next;
	}
}
int main() {
	doublylinkedlist mylist;
	
	mylist.pushfront(10);
	mylist.pushfront(234);
	mylist.pushfront(234);
	mylist.pushback(5);
	mylist.pushback(10);
	mylist.display();
	cout << endl;
	
	cout << "implementing erase functionality<" << endl;
	mylist.erase(234);
	cout << endl;
	mylist.display();

	
	
	/*cout<<mylist.front();
	cout << endl;
	cout << mylist.end();*/
}

