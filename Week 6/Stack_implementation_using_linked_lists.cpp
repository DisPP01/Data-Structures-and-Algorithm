#include <iostream>
#include <chrono> 

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        Node* temp = nullptr;
        while (top != nullptr) {
            temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    bool isFull() {
        return false; 
    }

    int stackTop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return top->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Elements in the stack:" << endl;
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " " ;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    auto start = chrono::high_resolution_clock::now();

    for (int i = 1; i <= 10; i++) {
        s.push(rand());
    }
    s.display();
    for (int i = 1; i <= 5; i++) {
        s.pop();
    }
    s.display();
    for (int i = 1; i <= 4; i++) {
        s.push(rand());
    }
    s.display();
    

    auto end = chrono::high_resolution_clock::now(); 
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start); 

    cout << "Time taken for all operations: " << duration.count() << " microseconds" << endl;

}