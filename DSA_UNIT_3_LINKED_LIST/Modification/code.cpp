#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void display(Node* head) {
    cout << "Linked List: ";
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void deleteNode(Node*& head, int key) {
    if (head == NULL)
        return;

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL &&
           temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    } else {
        cout << "Element not found" << endl;
    }
}

int main() {
    Node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);

    display(head);

    int key = 20;
    deleteNode(head, key);

    cout << "After Deletion: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}
