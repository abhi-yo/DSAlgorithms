#include<iostream>
using namespace std;
class Maths{
    public:
    int sum(int a,int b){
        return a+b;
    }
    int sum(int a,int b,int c){
        return a+b+c;
    }
    int sum(int a,float b){
        return a+b+10;
    }
};
int main(){
    Maths obj;
    cout<<obj.sum(2,5,7.12f);
    return 0;
}