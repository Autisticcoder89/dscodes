#include <iostream>
using namespace std;

// ---------------- NODE CLASS ----------------
class node {
private:
    int data;       // stores node value
    node* next;     // pointer to next node

public:
    // Constructor

    node(int new_data = 0, node* next = nullptr) {
        data = new_data;
        this->next = next;
    }
    node(int value) {
        data = value;
        next = nullptr;
    }

    // Getter for data
    int retrieve() const {
        return data;
    }

    // Setter for data
    void setdata(int value) {
        data = value;
    }

    // Getter for next node
    node* getnext() const {
        return next;
    }

    // Setter for next node
    void setnext(node* ptr) {
        next = ptr;
    }
};

// ---------------- CIRCULAR LINKED LIST CLASS ----------------
class CircularLinkedList {
private:
  
    node* listhead;     // pointer to first node
    node* tail;
    int size = 0;// pointer to last node

public:
    // Default constructor
    CircularLinkedList() {
        listhead = nullptr;
        tail = nullptr;
        size = 0;
    }
    node* gethead() {
        return listhead;
    }
    int getsize() {
        return size;
    }

    // Destructor (empty for now)
    ~CircularLinkedList() {
        // cleanup logic can be added later
    }
    bool ismepty() {
        return listhead == nullptr;
    }
    int count(int n) {
        int nodecount = 0;
        if (listhead == nullptr) {
            return -1;
        }
        for (node* ptr = listhead; ptr = ptr->getnext();) {
            if (ptr->retrieve()==n) {
                nodecount++;
            }
            if (ptr == listhead) {
                break;
            }
        }
        return nodecount;
    }
    void display() {
        if (listhead == nullptr) {
            cout << "-1";
        }
        node* ptr = listhead;
        do {
            cout << ptr->retrieve() << " ";
            ptr = ptr->getnext();
        } while (ptr!=listhead);
        cout << "null";
    }
    void pushfront(int n) {
        node* current = new node(n, nullptr);
        if (listhead == nullptr) {//if list is empty the node points towards itself
       
            current->setnext(current);
            listhead = current;
           
        }
        else {
            node* ptr = listhead;
            while (ptr->getnext()!= listhead) {
                ptr=ptr->getnext();
            }
            current->setnext(listhead);//making it circle
            ptr->setnext(current);
            listhead = current;

           

        }
        size++;
    }
    int popfront() {
        int e = listhead->retrieve();
        if (listhead == nullptr) {
            cout << "the list is empty";
            return -1;
        }
        if (listhead->getnext() == listhead) {
            delete listhead;
            listhead = nullptr;
            size--;
            return e;
        }
        node* last = listhead;
        while (last->getnext() != listhead) {
            last = last->getnext();
        }
        node* oldhead = listhead;
        listhead = listhead->getnext();
        last->setnext(listhead);
        delete oldhead;
        size--;
        return e;
    }
    void pushBack(int value) {
        node* newNode = new node(value);

        // Case 1: List is empty
        if (listhead == nullptr) {
            listhead = newNode;
            newNode->setnext(newNode);      // points to itself
            size++;
            return;
        }

        // Case 2: List has one or more nodes
        node* ptr = listhead;
        while (ptr->getnext() != listhead) { // find last node
            ptr = ptr->getnext();
        }

        ptr->setnext(newNode);              // last -> new node
        newNode->setnext(listhead);         // new node -> head
        size++;
    }

    int popEnd() {
        // Case 1: Empty list
        if (listhead == nullptr) {
            cout << "The list is empty.\n";
            return -1;
        }

        // Case 2: Only one node
        if (listhead->getnext() == listhead) {
            int val = listhead->retrieve();
            delete listhead;
            listhead = nullptr;
            size--;
            return val;
        }

        // Case 3: Multiple nodes
        node* prev = nullptr;
        node* current = listhead;

        // Traverse until current points to the last node
        while (current->getnext() != listhead) {
            prev = current;
            current = current->getnext();
        }

        // current is now the last node
        int val = current->retrieve();
        prev->setnext(listhead);   // previous node becomes new last
        delete current;
        size--;
        return val;
    }

    void erase(int n) {
        // Case 1: Empty list
        if (listhead == nullptr) {
            cout << "The list is empty.\n";
            return;
        }

        // Case 2: Only one node
        if (listhead->getnext() == listhead) {
            if (listhead->retrieve() == n) {
                delete listhead;
                listhead = nullptr;
                size--;
                cout << "Node deleted (it was the only node).\n";
            }
            else {
                cout << "Value not found.\n";
            }
            return;
        }

        // Case 3: Multiple nodes
        node* current = listhead;
        node* prev = nullptr;

        // Check if head itself has the value
        if (listhead->retrieve() == n) {
            // find last node to fix its next pointer
            node* last = listhead;
            while (last->getnext() != listhead)
                last = last->getnext();

            node* temp = listhead;
            listhead = listhead->getnext();
            last->setnext(listhead);
            delete temp;
            size--;
            cout << "Head node deleted.\n";
            return;
        }

        // Traverse to find node with value n
        do {
            prev = current;
            current = current->getnext();

            if (current->retrieve() == n) {
                prev->setnext(current->getnext());
                delete current;
                size--;
                cout << "Node with value " << n << " deleted.\n";
                return;
            }
        } while (current != listhead);

        cout << "Value not found in the list.\n";
    }




       

};


int main() {
    CircularLinkedList mylist;   
    mylist.pushfront(234);
    mylist.pushfront(124);
    mylist.pushfront(678);
    mylist.display();
    cout << endl;
    mylist.popfront();
    mylist.display();

    return 0;
}
