#include<iostream>
using namespace std;
int main(){
    int arr[5];
    cout<<"Enter the values of array: "<<endl;
    for(int i= 0; i<5;i++){
        cin>>arr[i];
    }
    //printing elements
    cout<<"Printing elements of array"<<endl;
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}