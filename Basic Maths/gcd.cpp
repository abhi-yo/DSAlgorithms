#include<iostream>
using namespace std;
int gcd(int A,int B){
    if(A==0)return B;
    if(B==0)return A;
    while(A>0 && B>0){
        if(A>B){
            A=A-B;

        }else{
            B=B-A;
        }
    }
    return A==0?B:A;
}
int main() {
    int a = 12;
    int b = 30;
    int result = gcd(a, b);
    cout << "The GCD of " << a << " and " << b << " is " << result << endl;
    return 0;
}