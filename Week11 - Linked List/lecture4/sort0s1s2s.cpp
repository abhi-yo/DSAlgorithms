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
void sortZeroOneTwo(Node*head){
    //A) Find count of 0s, 1s and 2s
    int zero=0;
    int one=0;
    int two=0;

    Node*temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            zero++;
        } else if(temp->data==1){
            one++;
        } else {
            two++;
        }
        temp=temp->next;
    }
    //B) Fill 0s, 1s and 2s in the original LL
    temp=head;
    //fill zeroes
    while(zero--){
        temp->data=0;
        temp=temp->next;
    } 
    //fill ones
    while(one--){
        temp->data=1;
        temp=temp->next;
    }
    //fill twos
    while(two--){
        temp->data=2;
        temp=temp->next;
    }
}
int main() {
    Node* head = new Node(2);
    Node* second = new Node(1);
    Node* third = new Node(0);
    Node* fourth = new Node(2);
    Node* fifth = new Node(1);
    Node* sixth = new Node(0);
    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = sixth;
    print(head);
    sortZeroOneTwo(head);
    print(head);
    return 0;
} 
