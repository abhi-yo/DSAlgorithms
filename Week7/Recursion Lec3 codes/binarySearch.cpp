#include <iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& v,int s,int e, int& key){
    //base case
    //case1->key not found
    if(s>e)//invalid array
    return -1;
    int mid=(s+e)/2;
    //case 2-> key found
    if(v[mid]==key)
    return mid;
    
    if(v[mid]<key){
        return binarySearch(v,mid+1,e,key);
        
    }else{
        return binarySearch(v,s,mid-1,key);
    }
}


int main()
{
    vector<int> v{10,20,40,60,70,90,99};
    int target=60;
    int n=v.size();
    int s=0;
    int e=n-1;
    int ans=binarySearch(v, s, e,target);
    cout<<"Answer is: "<<ans<<endl;

    return 0;
}