#include<iostream>
#include<vector>
using namespace std;
bool checkSorted(vector<int>&v,int&n,int i){
    //base case
    if(i==n-1){
        return true;
    }
    //1 case solve krunga
    if(v[i+1]<v[i])
    return false;
    
    //baaki recursion smbhal lega
    return checkSorted(v,n,i+1);
}
int main(){
    vector<int>v{10,20,30,50,60,15};
    int n=v.size();
    int i;
    bool isSorted=checkSorted(v,n,i);
    if(isSorted){
        cout<<"Array is sorted"<<endl;
    
    }else{
        cout<<"Array is not sorted"<<endl;
    }
    return 0;
}