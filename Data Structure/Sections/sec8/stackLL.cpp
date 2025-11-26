#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// معندناش هيد هنا خليك فاكر, هنقول توب عشان ديه ستاك
Node* top = NULL;

// push operation
void push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// pop operation
int pop() {
    if (top == NULL) {
        cout << "Stack Underflow\n";
        return -1;
    }
    Node* temp = top;
    int popped = temp->data;
    top = top->next;
    delete temp;
    return popped;
}

// peek operation
int peek() {
    if (top == NULL) {
        cout << "Stack is empty\n";
        return -1;
    }
    return top->data;
}
