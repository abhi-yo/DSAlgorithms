#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int>arr{5,4,3,2,1};
    int n=arr.size();
    //outerloop for number of rounds
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        //find index of minimum element from i to n.
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                //new minimum, then store
                minIndex=j;
            }
        }
        //swap
        swap(arr[i],arr[minIndex]);
    }
    //print sorted array
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}