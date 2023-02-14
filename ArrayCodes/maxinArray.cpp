
#include<iostream>
#include<limits.h>
using namespace std;
int main(){
    int arr[]={2,3,4,5,6,7,8,9,20,23,34,2,34};
    int size=13;
    int maxi =INT_MIN;
    for(int i=0;i<size;i++){
        if(arr[i]>maxi){
            maxi = arr[i];
        }

    }
    cout<<"max no.: "<<maxi<<endl;
    return 0;
}


