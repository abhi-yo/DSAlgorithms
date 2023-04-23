#include<iostream>
using namespace std;
class Node{
        public:
        int data;
        Node* next;

        Node(int data) {
                this->data = data;
                this->next = NULL;
        }
};

Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = curr -> next;
        while(curr != NULL) {
                next = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = next;
        }
        return prev;
}
void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void removeDuplicates(Node*&head){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        return;
    }
    //>1 node
    Node* curr=head;
    while(curr->next!=NULL){
        if((curr->data==curr->next->data)){
            //equal
            curr->next=curr->next->next;
        }else{
            curr=curr->next;
        }
    }
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(2);
    Node* fourth = new Node(3);
    Node* fifth = new Node(4);
    Node* sixth = new Node(4);
    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = sixth;
    print(head);
    removeDuplicates(head);
    print(head);
    return 0;
} 
