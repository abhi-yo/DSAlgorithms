#include<iostream>
using namespace std;
class A{
    public:
    int Physics;
};
class B{
    public:
    int Maths;
};
class C: public A,public B
{
    public:
    int Chemistry;
};
int main(){
    C obj;
    cout<<" "<<obj.Physics<<" "<<obj.Chemistry<<" "<<obj.Maths<<endl;
    return 0;
}