// In this question we are:-
// a)checking if loop is present or not 
// b)finding the starting point of the loop 
// c)removing the loop

#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
};
void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
int length(Node* head){
    int len = 0;
    while(head != NULL){
        head = head->next;
        len++;
    }
    return len;
}
// using Floyd's cycle detection algorithm
bool checkForLoop(Node*&head){
    if(head==NULL){
        return false;
    }
    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast ->next;
            slow= slow->next;
        }
        if(fast==slow){
            return true;
        }
    }
    //fast NULL hogaya
    return false;
}
//getting the starting point of the loop
Node*startingPointLoop(Node*&head){
    if(head==NULL){
        return NULL;
    }
    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast ->next;
            slow= slow->next;
        }
        if(slow==fast){
            slow=head;
            break;
        }
    }
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}
//removing the loop from the linked list
Node*removeLoop(Node*&head){
    if(head==NULL){
        return NULL;
    }
    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast ->next;
            slow= slow->next;
        }
        if(slow==fast){
            slow=head;
            break;
        }
    }
    Node*prev=fast;
    while(slow!=fast){
        prev=fast;
        slow=slow->next;
        fast=fast->next;
    }
    prev->next=NULL;
    return slow;
}
int main() {
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);
    Node* eighth = new Node(80);
    Node* ninth = new Node(90);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = fourth;
    // checking if loop or not
    if (checkForLoop(head)) {
        cout << "Loop is present in the Linked List." << endl;
    } else {
        cout << "Loop is not present in the Linked List." << endl;
    }

    // finding the starting point of the loop
    cout << "Starting Point of Loop is: " << startingPointLoop(head) -> data << endl;

    // removing the loop
    removeLoop(head);
    // now checking if loop is present or not
    if (checkForLoop(head)) {
        cout << "Loop is present in the Linked List." << endl;
    } else {
        cout << "Loop is not present in the Linked List." << endl;
    }
    return 0;
}
