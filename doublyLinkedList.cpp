#include <bits/stdc++.h>
using namespace std;
class Node {
public:
  int data;
  Node *prev;
  Node *next;

  Node(int val) {
    data = val;
    prev = next = NULL;
  }
};

class DoublyList {
  Node *head;
  Node *tail;

public:
  DoublyList() { head = tail = NULL; }

  void push_front(int val) {

    Node *newNode = new Node(val);
    if (head == NULL) {
      head = tail = newNode;
      return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
  void push_back(int val) {

    Node *newNode = new Node(val);
    if (head == NULL) {
      head = tail = newNode;

    } else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
  }
  void pop_front() {

    if (head == NULL) {
      cout << "List is empty" << endl;
      return;
    }
    if (head->next == NULL) {
      delete head;
      return;
    }
    Node *todel = head;
    head = head->next;
    todel->next = NULL;
    delete todel;
  }

  void pop_back() {
    if (head == NULL) {
      cout << "List is empty" << endl;
      return;
    }
    if (head->next == NULL) {
      delete head;
      return;
    }
      Node* todel=tail;
      tail=tail->prev;
      tail->next=NULL;
      delete todel;


  }

  void display() {
    Node *temp = head;
    while (temp) {
      cout << temp->data << "<->";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main() {

  DoublyList dll;
  dll.push_front(1);
  dll.push_front(2);
  dll.push_front(3);
  dll.push_back(10);
  dll.display();
  dll.pop_front();
  dll.display();
  dll.pop_back();
  dll.display();
  return 0;
}