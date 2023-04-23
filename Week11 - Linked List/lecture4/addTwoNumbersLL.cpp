#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void print(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* reverse(Node*head){
    Node* prev=NULL;
    Node* curr=head;
    Node* next= curr-> next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

// Function to add two numbers represented by linked list
Node* solve(Node*&head1,Node*&head2){
    //Step 1: reverse both LL
    head1=reverse(head1);
    head2=reverse(head2);
    //Step 2: add both LL
    Node* ansHead=NULL;
    Node* ansTail=NULL;
    int carry =0;
    while(head1!=NULL&&head2!=NULL){
        int sum=carry + head1-> data+head2-> data;
        int digit =sum%10;
        carry=sum/10;
        Node*newNode=new Node(digit);
        if(ansHead==NULL){
            //first node insert krre hain
            ansHead=newNode;
            ansTail=newNode;
        }else{
            ansTail->next=newNode;
            ansTail=newNode;
        }
        head1=head1->next;
        head2=head2->next;
    }
    while(head1!=NULL){
        int sum=carry+head1->data;
        int digit=sum%10;
        carry = sum/10;
        Node*newNode=new Node(digit);
        ansTail-> next=newNode;
        ansTail=newNode;
        head1=head1->next;
    }
    // if length of head2 is greater than head1
    while(head2!=NULL){
        int sum=carry+head2->data;
        int digit=sum%10;
        carry = sum/10;
        Node*newNode=new Node(digit);
        ansTail-> next=newNode;
        ansTail=newNode;
        head2=head2->next;
    }
    //handle carry alg se
    while(carry!=0){
        int sum=carry;
        int digit=sum%10;
        carry = sum/10;
        Node*newNode=new Node(digit);
        ansTail-> next=newNode;
        ansTail=newNode;
    }
    //step3: reverse the ans linked list
    ansHead = reverse(ansHead);
    return ansHead;
}

int main(){
    Node* head1 = new Node(12);
    Node* second1 = new Node(2);
    head1 -> next = second1;
    Node* head2 = new Node(1);
    Node* second2 = new Node(3);
    head2 -> next = second2;
    // second2 -> next = third2;
    Node* ans = solve(head1, head2);
    print(ans);
    return 0;
} 