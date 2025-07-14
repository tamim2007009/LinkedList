#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node *head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at end
    void insert(int data) {
        Node *newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at head
    void insertAtHead(int data) {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Insert at given position (1-indexed)
    void insertAtPosition(int data, int pos) {
        if (pos == 1) {
            insertAtHead(data);
            return;
        }
        Node *newNode = new Node(data);
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position out of bounds\n";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete by value
    void deleteByValue(int value) {
        if (!head)
            return;
        if (head->data == value) {
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        Node *temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Value not found\n";
            return;
        }
        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Delete by position (1-indexed)
    void deleteAtPosition(int pos) {
        if (!head)
            return;
        if (pos == 1) {
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of bounds\n";
            return;
        }
        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Search a value
    bool search(int key) {
        Node *temp = head;
        while (temp) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Get length
    int length() {
        int cnt = 0;
        Node *temp = head;
        while (temp) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    // Reverse list
    void reverse() {
        Node *prev = nullptr, *curr = head, *next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // Display list
    void display() {
        Node *temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    LinkedList list;

    // Example usage
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        list.insert(val);
    }

    cout << "Initial list:\n";
    list.display();

    cout << "Length: " << list.length() << "\n";

    list.insertAtHead(99);
    cout << "After inserting 99 at head:\n";
    list.display();

    list.insertAtPosition(55, 3);
    cout << "After inserting 55 at position 3:\n";
    list.display();

    list.deleteByValue(99);
    cout << "After deleting value 99:\n";
    list.display();

    list.deleteAtPosition(2);
    cout << "After deleting node at position 2:\n";
    list.display();

    cout << "Is 55 in the list? " << (list.search(55) ? "Yes" : "No") << "\n";

    list.reverse();
    cout << "Reversed list:\n";
    list.display();

    return 0;
}
