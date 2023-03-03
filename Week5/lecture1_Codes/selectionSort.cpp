#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr{5,4,3,2,1,0};
    int n=arr.size();
    //outer loop for number of rounds 
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        //finds index of minimum element from i to n.
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j; //new minimum, then store
            }
        }
        //swap
        swap(arr[i],arr[minIndex]);
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}
