#include<iostream>
using namespace std;

class Stack{
    public:
    int* arr;
    int top;
    int size;
    Stack(int size){
        arr = new int[size];
        this->size = size;
        top = -1;
    }
    void push(int data){
        if(top+1 < size){
            //space is available
            top++;
            arr[top] = data;
        }else{
            cout<<"Stack overflow"<<endl;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"Stack underflow"<<endl;
        }else{
            top--;
        }
    }
    int getTop(){
        if(top==-1){
            cout<<"No element in stack"<<endl;
            return -1;
        }else{
            return arr[top];
        }
    }
    int getSize(){
        return top+1;
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    Stack s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    while(!s.isEmpty()){
        cout<<s.getTop()<<endl;
        s.pop();
    }
    return 0;
}
