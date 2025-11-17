#include <iostream>
using namespace std;

#define MAX 100   // maximum size of stack

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;   // stack initially empty
    }

    // Push element into stack
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << x << endl;
            return;
        }
        arr[++top] = x;
        cout << x << " pushed to stack\n";
    }

    // Pop element from stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop\n";
            return -1;
        }
        return arr[top--];
    }

    // Return top element without removing
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX - 1);
    }

    // Display stack contents
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Popped: " << s.pop() << endl;
    cout << "Top element: " << s.peek() << endl;

    s.display();

    return 0;
}
