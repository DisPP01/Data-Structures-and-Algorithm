#include <iostream>
#include <chrono> 

using namespace std;

class Stack {
private:
    int* arr;
    int size;
    int topId;

public:
    Stack(int s) {
        arr = new int[s];
        size = s;
        topId = -1;
    }


    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++topId] = value;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return;
        }
        topId--;
    }

    bool isEmpty() {
        return topId == -1;
    }

    bool isFull() {
        return topId == size - 1;
    }

    int stackTop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return arr[topId];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "All the elements in the stack:" << endl;
        for (int i = topId; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the Stack Size : ";
    cin >> size;

    Stack s(size);

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