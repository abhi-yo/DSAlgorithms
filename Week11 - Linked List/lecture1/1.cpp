#include<iostream>
using namespace std;

// Node is created
class Node{
    public:
    int data;
    Node* next;

//Constructor for node
    Node(){
        this->data=0;
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void print(Node* &head){
    Node* temp=head;
    while(temp!= NULL){
        cout<<temp->data<<" " ;
        temp=temp->next;
    } 
}
int main(){
    //creating all nodes 
    Node*first=new Node(10);
    Node*second=new Node(20);
    Node*third=new Node(30);
    Node*fourth=new Node(40);
    Node*fifth=new Node(50);

    //linking all the nodes
    first->next= second;
    second->next= third;
    third->next= fourth;
    fourth->next= fifth;

    cout<<"Printing the linked list"<<endl;
    print(first);
}