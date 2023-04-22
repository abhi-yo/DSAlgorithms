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
void insertAtHead(Node* &head, int data){
    Node* n = new Node(data);
    n->next = head;
    head = n;
}
void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
Node* getMiddle(Node*&head){
    if(head==NULL){
        return head;
    }
    if(head->next==NULL){
        //only 1 node
        return head;
    }
    //LL will have more than 1 node.
    Node* slow=head;
    Node* fast=head;
    while(slow!=NULL&& fast!=NULL){
        fast= fast-> next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    }
    return slow;
}
int length(Node* head){
    int len = 0;
    while(head != NULL){
        head = head->next;
        len++;
    }
    return len;
}

int main(){
    Node* head = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    print(head);
    Node* middle = getMiddle(head);
    cout << "Middle node: " << middle->data << endl;
    print(head);
    return 0;
}
