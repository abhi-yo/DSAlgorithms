// same operator can be used for multiple purposes.
//Syntax: return_type operator + ( ){}
#include<iostream>
using namespace std;
class Parameter{
    public:
    int value;
    void operator + (Parameter& obj2){
        int Value1=this->value;
        int Value2=obj2.value;
        cout<<(Value2-Value1)<<endl;
    }
};
int main(){
    Parameter obj1,obj2;
    obj1.value=7;
    obj2.value=2;
    
    //this will print diffrence between them
    obj1+obj2;
}