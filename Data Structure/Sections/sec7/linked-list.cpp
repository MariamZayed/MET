#include <iostream>
using namespace std;

struct Node {
    int key;
    int data;
    Node* next;
};

Node* head = NULL;

void insertFirst(int key, int data) {
    Node* link = new Node();
    link->key = key;
    link->data = data;
    link->next = head;
    head = link;
}

Node* deleteFirst() {
    if (head == NULL) return NULL;
    Node* temp = head;
    head = head->next;
    return temp;
}

Node* find(int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->key == key)
            return current;
        current = current->next;
    }
    return NULL;
}

Node* delet(int key) {
    Node* current = head;
    Node* previous = NULL;

    while (current != NULL && current->key != key) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) return NULL;

    if (current == head) {
        head = head->next;
    } else {
        previous->next = current->next;
    }

    return current;
}

void printList() {
    Node* ptr = head;
    cout << "List: ";
    while (ptr != NULL) {
        cout << "(" << ptr->key << ", " << ptr->data << ") → ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

void reverse(Node** head_ref) {
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head_ref = prev;
}

int main() {
    insertFirst(1,10);
    insertFirst(2,20);
    insertFirst(3,30);

    cout << "Original List: ";
    printList();

    reverse(&head);
    cout << "Reversed List: ";
    printList();
}
