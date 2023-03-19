//Here we are using backtracking concept.
#include<iostream>
#include<string>
using namespace std;
void printPermutation(string&str,int i){
    //base case
    if(i>=str.length()){
        cout<<str<<" ";
        return;
    }
    //swaping
    for(int j=i;j<str.length();j++){
        //swap
        swap(str[i],str[j]);
        //recurence call
        printPermutation(str,i+1);
    //backtracking usage- to recreate original string
        swap(str[i],str[j]);
    }
}
int main(){
    string str="abc";
    int i=0;
    printPermutation(str,i);
    return 0;
}