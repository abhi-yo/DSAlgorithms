#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, Node* &tail, int data) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* reverseRecursive(Node* &prev, Node* &curr) {
    if (curr == NULL) {
        return prev;
    }
    Node* forward = curr->next;
    curr->next = prev;
    return reverseRecursive(curr, forward);
}

Node* reverseIterative(Node* &prev, Node* &curr) {
    while (curr != NULL) {
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

int main() {
    Node* head = new Node(10);
    Node* tail = head;
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);
    print(head);
    cout << endl;
    Node* prev = NULL;
    Node* curr = head;
    Node* next = curr->next;
    Node* newHead = reverseIterative(prev, curr);
    print(newHead);
    return 0;
}
