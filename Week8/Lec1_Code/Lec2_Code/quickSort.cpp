#include<iostream>
using namespace std;
int partition(int arr[],int s,int e){
    //step1: Choose pivot element (generally we are taking first element as the pivot element)
    int pivotIndex=s;
    int pivotElement=arr[s];
    //step2: find position of pivot and place it there
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivotElement){
            count++;
        }
    }
    //jab hum loop se bahar niklenge toh pivot ka right posn ka index ready hai
    int rightIndex=s+count;
    swap(arr[pivotIndex],arr[rightIndex]);
    pivotIndex=rightIndex;
    //step3: left mei chote and right mei bade
    int i=s;
    int j=e;
    while(i<pivotIndex&&j>pivotIndex){
        while(arr[i]<=pivotElement){
            i++;
        }
        while(arr[j]>pivotElement){
            j--;
        }
    }
    //2 case hoskte hain ya toh sab sahi ho ya toh you found elements to be swapped i.e.(right mei pivot se chota or left mei pivot se bada)
    if(i<pivotIndex&&j>pivotIndex){
        swap(arr[i],arr[j]);
    }
    return pivotIndex;
}
void quickSort(int arr[],int s,int e){
    //base case
    if(s>=e)
    return;

    //partition logic 
    int p=partition(arr,s,e);

    //recursive call
    //for left
    quickSort(arr,s,p-1);
    //for right
    quickSort(arr,p+1,e);
}
int main(){
    int arr[]={8,1,3,4,20,50,30};
    int n=7;
    int s=0;
    int e=n-1;
    quickSort(arr,s,e);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}