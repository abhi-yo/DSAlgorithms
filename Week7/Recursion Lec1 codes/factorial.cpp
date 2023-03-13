#include<iostream>
using namespace std;
int fact(int n){
    //base case
    if(n==1)return 1;
    int chotiProblem= fact(n-1);
    int badiProblem = n*chotiProblem;
    return badiProblem;
}
int main(){
    int n;
    cin>>n;
    int badiProblem=fact(n);
    cout<<badiProblem;
}