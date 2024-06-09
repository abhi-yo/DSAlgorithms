#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};


void insertAtHead(Node*&head, int data){
  Node*newnode = new Node(data);
  newnode->next = head;
  head = newnode;
}

void insertAtTail(Node*&tail, int data){
  Node*newnode = new Node(data);
  tail->next = newnode;
  tail = newnode;
}


void insertAtPosition(Node*&head,Node*&tail,int pos, int data){
  if(pos==0){
    insertAtHead(head,data);
    if(tail==NULL){
      tail = head;
    }
    return;
  }
  Node* current = head;
  
  for(int i=1; i<pos && current!=NULL ; ++i){
    current = current->next;
  }
  
  if(current==NULL){
    insertAtTail(tail,data);
  }else{
    Node* newnode = new Node(data);
    newnode->next = current->next;
    current->next = newnode;
    if (newnode->next == NULL) { // Ensure the tail is updated if new node is inserted at the end
      tail = newnode;
    }
  }
}

int findLength(Node*&head){
  int x= 0;
  Node*temp = head;
  while(temp!=NULL){
    temp = temp->next;
    x++;
  }
  return x;
}

void deleteop(int pos, Node*&head, Node*&tail){
  
  if(head==NULL){
    return;
  }
  
  if(pos==0){
    Node*temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
    if(head == NULL){
      tail = NULL;
    }
    return;
  }
  
  int len = findLength(head);
  
  Node* current = head;
  Node* prev = NULL;
  for(int i =0;i<pos; i++){
    prev = current;
    current = current->next;
  }
  prev->next = current->next;
  if(current->next==NULL){
    tail = prev;
  }
  current->next =NULL;
  delete current;
}




void print(Node*head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head = head->next;
  }
  cout<<endl;
}



int main() 
{
  Node* head = NULL;
  Node* tail = NULL;
  insertAtHead(head,20);
  if(tail==NULL){
    tail = head;
  }
  insertAtTail(tail,10);
  if(head->next==NULL){
    head->next = tail;
  }
  insertAtHead(head,5);
  insertAtPosition(head,tail,0,1);
  deleteop(0, head, tail);
  print(head); 

  deleteop(2, head, tail);
  print(head);

  return 0;
}
