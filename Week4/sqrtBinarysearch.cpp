#include<iostream>
using namespace std;
int findSqrt(int n){
    int ans;
    int s=0;
    int e=n;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(mid*mid==n)
            return mid;
        if(mid*mid>n)
            e=mid-1;
        else{
            s=mid+1;
        }
    mid=s+(e-s)/2;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int ans=findSqrt(n);
    cout<<"Ans is:"<<ans<<endl;
    return 0;
}
