#include <iostream>
using namespace std;

// ---------------- Node Class ----------------
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// ---------------- List Class ----------------
class List {
private:
    Node* list_head;
    int list_size;

public:
    // Constructor
    List() {
        list_head = nullptr;
        list_size = 0;
    }

    // Destructor
    ~List() {
        while (!empty())
            pop_front();
    }

    // ---------- Accessors ----------
    bool empty() const {
        return list_head == nullptr;
    }

    int size() const {
        return list_size;
    }

    // Display for debugging
    void display() const {
        if (empty()) {
            cout << "List is empty.\n";
            return;
        }

        Node* ptr = list_head;
        cout << "List elements: ";
        while (ptr != nullptr) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    // ---------- Mutators ----------

    // ✅ 1. Push Front — insert at the beginning
    void push_front(int value) {
        Node* newNode = new Node(value);
        newNode->next = list_head;
        list_head = newNode;
        list_size++;
    }

    // ✅ 2. Push End — insert at the end
    void push_end(int value) {
        Node* newNode = new Node(value);

        // Case 1: Empty list
        if (list_head == nullptr) {
            list_head = newNode;
        }
        else {
            // Case 2: Traverse to last node
            Node* ptr = list_head;
            while (ptr->next != nullptr) {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }

        list_size++;
    }

    // ✅ 3. Pop Front — delete first node
    int pop_front() {
        if (empty()) {
            cout << "List is empty.\n";
            return -1;
        }

        int val = list_head->data;
        Node* temp = list_head;
        list_head = list_head->next;
        delete temp;
        list_size--;
        return val;
    }

    // ✅ 4. Pop End — delete last node
    int pop_end() {
        if (empty()) {
            cout << "List is empty.\n";
            return -1;
        }

        int val;

        // Case 1: Only one node
        if (list_head->next == nullptr) {
            val = list_head->data;
            delete list_head;
            list_head = nullptr;
        }
        else {
            // Case 2: Traverse to second-last node
            Node* prev = nullptr;
            Node* curr = list_head;

            while (curr->next != nullptr) {
                prev = curr;
                curr = curr->next;
            }

            val = curr->data;
            delete curr;
            prev->next = nullptr;
        }

        list_size--;
        return val;
    }

    // ✅ 5. Erase — delete the first occurrence of a given value
    int erase(int value) {
        if (empty()) {
            cout << "List is empty.\n";
            return -1;
        }

        Node* curr = list_head;
        Node* prev = nullptr;

        // Case 1: Value found at head
        if (curr->data == value) {
            list_head = curr->next;
            delete curr;
            list_size--;
            return value;
        }

        // Case 2: Search through list
        while (curr != nullptr && curr->data != value) {
            prev = curr;
            curr = curr->next;
        }

        // Value not found
        if (curr == nullptr) {
            cout << "Value not found.\n";
            return -1;
        }

        // Case 3: Found in middle or end
        prev->next = curr->next;
        delete curr;
        list_size--;
        return value;
    }
};

// ---------------- Main Function ----------------
int main() {
    List mylist;

    mylist.push_front(10);
    mylist.push_front(5);
    mylist.push_end(15);
    mylist.push_end(20);

    mylist.display();

    mylist.pop_front();
    mylist.display();

    mylist.pop_end();
    mylist.display();

    mylist.erase(15);
    mylist.display();

    cout << "List size: " << mylist.size() << endl;
    return 0;
}
