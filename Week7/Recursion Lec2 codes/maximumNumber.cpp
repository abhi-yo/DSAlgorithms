#include <iostream>
#include<limits.h>
using namespace std;
void findMax(int arr[],int n,int i, int&maxi){
    //base case
    if(i>=n){
        return;
    }
    //1 case solve krna hai
    maxi=max(maxi,arr[i]);

    //baaki recursion samhal lega
    findMax(arr,n,i+1,maxi);
}
int main(){
    int arr[]={10,20,90,70,20};
    int n=5;
    int maxi=INT_MIN;
    int i=0;
    findMax(arr,n,i,maxi);
    cout<<maxi<<endl;
    return 0;

}