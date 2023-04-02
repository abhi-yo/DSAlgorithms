#include<iostream>
using namespace std;
class Animal{
    public:
    int age;
    int weight;
    void eat(){
        cout<<"Eating"<<endl;
    }
};
class Dog:public Animal{

};
int main(){
    Dog d1;
    d1.eat();
    return 0;
}