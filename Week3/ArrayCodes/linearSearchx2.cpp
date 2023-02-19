//Linear search code without use of functions.
#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int size=8;
    bool flag=0;
    int key;
    cout<<"Enter key: "<<endl;
    cin>>key;
    for(int i=0;i<8;i++){
        if(arr[i]==key){
            flag=1;
            break;
        }
    }
    if(flag)
        cout<<"present"<<endl;
    else
        cout<<"absent"<<endl;
    return 0;
}