#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

void displayStack(stack<Node*> s) {
    cout << "Stack (top to bottom): ";
    if (s.empty())
        cout << "Empty";

    while (!s.empty()) {
        cout << s.top()->data << " ";
        s.pop();
    }
    cout << endl;
}

void inorder(Node* root) {
    stack<Node*> s;
    Node* current = root;
    int maxSize = 0;

    cout << "Inorder Traversal: ";

    while (current != NULL || !s.empty()) {
        while (current != NULL) {
            s.push(current);

            if ((int)s.size() > maxSize)
                maxSize = s.size();

            displayStack(s);
            current = current->left;
        }

        current = s.top();
        s.pop();

        cout << current->data << " ";
        displayStack(s);

        current = current->right;
    }

    cout << "\nMaximum Stack Size: "
         << maxSize << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    inorder(root);

    return 0;
}
