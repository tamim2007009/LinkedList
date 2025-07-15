#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int v) {
        data = v;
        next = NULL;
    }
};

class CircularList {
    Node *tail;

public:
    CircularList() {
        tail = NULL;
    }

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }

    void display() {
        if (tail == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = tail->next;  // start from head
        do {
            cout << temp->data << "<->";
            temp = temp->next;
        } while (temp != tail->next);

        cout << " (circular)" << endl;
    }
};

int main() {
    CircularList cl;
    cl.insertAtHead(5);
    cl.insertAtHead(6);
    cl.insertAtHead(8);
    cl.insertAtHead(10);
    cl.display();

    return 0;
}
