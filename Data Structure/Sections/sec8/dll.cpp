#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// global head
Node* head = NULL;


///--------------------------------
void insertFirst(int key, int data) {
    Node* link = new Node();
    link->key = key;
    link->data = data;
    link->next = head;
    head = link;
}

// Insert at End
// -----------------------------------------------
void insertEnd(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    // لو الليست فاضية
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    // امشي لآخر نود
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // اربطي النود الجديدة
    temp->next = newNode;
    newNode->prev = temp;
}

// -----------------------------------------------
// Insert Before a Given Node
// -----------------------------------------------
void insertBefore(Node* nextNode, int data) {

    // لو النود اللي هندخل قبلها مش موجودة
    if (nextNode == NULL) {
        cout << "Given node cannot be NULL\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = data;

    newNode->prev = nextNode->prev;
    newNode->next = nextNode;

    // لو هنضيف قبل الـ head
    if (nextNode->prev != NULL) {
        nextNode->prev->next = newNode;
    } else {
        head = newNode;   // النود الجديدة بقت الهيد
    }

    nextNode->prev = newNode;
}

// -----------------------------------------------
// Display the list
// -----------------------------------------------
void printList() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// -----------------------------------------------
// Example usage
// -----------------------------------------------
int main() {

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    cout << "DLL after insertEnd:\n";
    printList();

    // نجيب النود اللي فيها 20 مثلاً
    Node* node20 = head->next;

    insertBefore(node20, 15);

    cout << "DLL after insertBefore(20):\n";
    printList();

    return 0;
}
