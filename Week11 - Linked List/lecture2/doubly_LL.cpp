#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int getLength(Node* &head){
    Node* temp = head;
    int len = 1;
    while(temp->next != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtTail(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insertAtPosition(int pos, Node* &head, Node* &tail, int data){
    if(pos == 1){
        insertAtHead(head, tail, data);
        return;
    }
    int len = getLength(head);
    if(pos > len){
        insertAtTail(head, tail, data);
        return;
    }
    int i = 1;
    Node* prevNode = head;
    while(i < pos - 1){
        prevNode = prevNode->next;
        i++;
    }
    Node* curr = prevNode->next;
    Node* newNode = new Node(data);
    prevNode->next = newNode;
    newNode->prev = prevNode;
    curr->prev = newNode;
    newNode->next = curr;
}

void deleteOperation(Node* &head, Node* &tail, int pos){
    if(pos == 1){
        Node* toDelete = head;
        head = head->next;
        head->prev = NULL;
        delete toDelete;
        return;
    }
    int len = getLength(head);
    if(pos >= len){
        Node* toDelete = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete toDelete;
        return;
    }
    int i = 1;
    Node* prevNode = head;
    while(i < pos - 1){
        prevNode = prevNode->next;
        i++;
    }
    Node* toDelete = prevNode->next;
    Node* nextNode = toDelete->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    delete toDelete;
}

int main() {
    Node* head = new Node(10);
    Node* tail = head;

    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);

    insertAtPosition(5, head, tail, 60);

    print(head);
    cout << endl;

    deleteOperation(head, tail, 3);

    print(head);
    cout << endl;

    deleteOperation(head, tail, 1);

    print(head);
    cout << endl;

    deleteOperation(head, tail, getLength(head));

    print(head);
    cout << endl;

    return 0;
}
