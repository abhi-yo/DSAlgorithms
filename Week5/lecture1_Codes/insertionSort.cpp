#include <iostream>
#include<vector>
using namespace std;

int main()
{
    //optimise bubble sort
    vector<int>arr{10,1,7,6,14,9};
    int n=arr.size();
    for(int i=1;i<n;i++){
        //Step A: Fetch
        int val=arr[i];
        //Step B: Compare
        int j = i - 1;
        for(;j>=0;j--){
            //StepC: Shift
            if(arr[j]>val&& j>=0){
                arr[j+1]=arr[j];
            }
            else{
                //stop
                break;
            }
        }
        //StepD: Copy
        arr[j+1]=val;
        
    }
    //print sorted array
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}