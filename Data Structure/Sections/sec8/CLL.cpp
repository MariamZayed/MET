#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
};

// insert in empty list
CNode* addToEmpty(int data) {
    CNode* temp = new CNode();
    temp->data = data;
    temp->next = temp;
    return temp;
}

// insert at beginning
CNode* addBegin(CNode* last, int data) {
    if (last == NULL)
        return addToEmpty(data);

    CNode* temp = new CNode();
    temp->data = data;
    temp->next = last->next;
    last->next = temp;
    return last;
}

// insert at end
CNode* addEnd(CNode* last, int data) {
    if (last == NULL)
        return addToEmpty(data);

    CNode* temp = new CNode();
    temp->data = data;
    temp->next = last->next;
    last->next = temp;
    last = temp;
    return last;
}

// insert after specific node
CNode* addAfter(CNode* last, int data, int item) {
    if (last == NULL)
        return NULL;

    CNode* p = last->next;

    do {
        if (p->data == item) {
            CNode* temp = new CNode();
            temp->data = data;
            temp->next = p->next;
            p->next = temp;

            if (p == last)
                last = temp;

            return last;
        }
        p = p->next;
    } while (p != last->next);

    cout << "Item not found\n";
    return last;
}
