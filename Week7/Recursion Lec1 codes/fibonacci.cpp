#include<iostream>
using namespace std;
int fib(int n){
    if(n==1)return 0;
    if(n==2)return 1;
    int ans=fib(n-1)+fib(n-2);
    return ans;
}
int main(){
    int n;
    cin>>n;
    int ans=fib(n);
    cout<<ans;
}

//fibonacci series is -> 0,1,1,2,3,5,8,13.... 
//         the diff of : numbers after first two index is 2-1=1, 3-2=1, 5-3=2 is equal to the no. behind them.