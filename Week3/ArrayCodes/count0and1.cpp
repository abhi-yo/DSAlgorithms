#include<iostream>
using namespace std;
void printZero(){
    int arr[]={1,0,1,1,1,0,0,1};
    int size=7;
    int numZero=0;
    int numOne=0;
    for(int i=0;i<size;i++){
        if(arr[i]==0){
            numZero++;
        }if(arr[i]==1){
            numOne++;
        }
    }
}
int main(){
    for(int i = 0;i<5; i++){
        printZero();
    }
    return 0;
}                                                       