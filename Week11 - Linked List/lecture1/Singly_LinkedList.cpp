#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Destructor to delete a node
    ~Node() {
        cout << "Node with value: " << this->data << " deleted" << endl;
    }
};

// Insert a node at the head of the linked list
void insertAtHead(Node* &head, Node* &tail, int data) {
    // Check for empty linked list
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    } else {
        // Step 1: create a new node
        Node* newNode = new Node(data);
        // Step 2: connect with the head node
        newNode -> next = head;
        // Step 3: update head
        head = newNode;
    }
}

// Insert a node at the end of the linked list
void insertAtTail(Node* &head, Node* &tail, int data) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // Step 1: create a new node
    Node* newNode = new Node(data);
    // Step 2: connect with the tail node
    tail->next = newNode;
    // Step 3: update tail
    tail = newNode;
}

// Print the linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Find the length of the linked list
int findLength(Node* &head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

// Insert a node at a given position in the linked list
void insertAtPosition(int data, int position, Node* &head, Node* &tail) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // Step 1: find the position: prev & curr
    if (position == 0) {
        insertAtHead(head, tail , data);
        return;
    }

    int len = findLength(head);

    if (position >= len) {
        insertAtTail(head, tail, data);
        return;
    }

    // Step 1: find prev and curr
    int i = 1;
    Node* prev = head;
    while (i < position) {
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;

    // Step 2: create a new node
    Node* newNode = new Node(data);
    // Step 3: connect with the next node
    newNode->next = curr;
    // Step 4: connect with the previous node
    prev->next = newNode;
}

// Delete a node at a given position in the linked list
void deleteNode(int position, Node* &head, Node* &tail) {
    if (head == NULL) {
        cout << "Cannot delete, linked list is empty" << endl;
        return;
    }
    
    Node* curr = head;
    Node* prev = NULL;
    
    // Find the node to delete
    for (int i = 0; curr != NULL && i < position; i++) {
        prev = curr;
        curr = curr->next;
    }
    
    // If position is greater than length of linked list
    if (curr == NULL) {
        cout << "Cannot delete, position is greater than length of linked list" << endl;
        return;
    }
    
    // If deleting the head node
    if (prev == NULL) {
        head = curr->next;
    } else {
        prev->next = curr->next;
    }
    
    // If deleting the tail node
    if (curr == tail) {
        tail = prev;
    }
    
    // Delete the node
    delete curr;
}


int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Insert nodes at head
    insertAtHead(head, tail, 1);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 3);

    // Insert nodes at tail
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);

    // Insert node at a position
    insertAtPosition(6, 2, head, tail);

    // Delete node at a position
    deleteNode(3, head, tail);

    // Print the linked list
    print(head);

    return 0;
}
