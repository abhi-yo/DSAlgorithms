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
int length(Node* head){
    int len = 0;
    while(head != NULL){
        head = head->next;
        len++;
    }
    return len;
}

Node* reverseKNodes(Node*&head, int k){
    if(head==NULL){
        return head;
    }
    if(head->next==NULL){
        //only 1 node
        return head;
    }
    int len=length(head);
    if(k>len){
        return head;
    }
    //if reach here i.e. no. of nodes is greater than k
    //Step A: Reverse first k nodes
    Node*prev=NULL;
    Node*curr=head;
    Node*forward=curr->next;
    int count=0;
    while(count<k){
        forward = curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }
    //Step B: Reverse the remaining nodes
    if(forward!=NULL){
        //if we have nodes left to reverse
        head->next=reverseKNodes(forward, k);
    }
    //Step C: Return the new head
    return prev;
}

int main(){
    Node* head = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    print(head);
    // reverse k nodes
    int k;
    cin>>k;
    head=reverseKNodes(head, k);
    print(head);
}
