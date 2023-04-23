#include<iostream>
#include<stack>
using namespace std;
void printMiddleElement(stack<int>&s,int&totalSize){
    //base case
    if(s.size()==(totalSize/2)+1){
        cout<<"Middle element is:"<<s.top()<<endl;
        return;
    }
    int temp=s.top();
    s.pop();
    //recursive call
    printMiddleElement(s,totalSize);
    //backtracking
    s.push(temp);
}
int main(){
    stack<int>s;
    int totalSize;
    cout<<"Enter the total size of stack:";
    cin>>totalSize;
    for(int i=0;i<totalSize;i++){
        int data;
        cin>>data;
        s.push(data);
    }
    printMiddleElement(s,totalSize);
    return 0;
}