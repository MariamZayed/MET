#include <iostream>
using namespace std;

#define MAXSIZE 100
int queue[MAXSIZE];
int front = -1, rear = -1;

bool isFull() {
    return rear == MAXSIZE - 1;
}

bool isEmpty() {
    return (front == -1 || front > rear);
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow!" << endl;
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = value;
    cout << value << " inserted into queue." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow!" << endl;
        return;
    }
    cout << "Deleted: " << queue[front] << endl;
    front++;
    if (front > rear) {
        front = rear = -1;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++)
        cout << queue[i] << " ";
    cout << endl;
}

int main() {
    int choice, value;
    do {
        cout << "\n1) Enqueue\n2) Dequeue\n3) Display\n4) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 4);
    return 0;
}
