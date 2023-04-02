#include<iostream>
using namespace std;

class Animal{
    int age;
    
    public:
        // Destructor
        ~Animal(){
            cout<<"Destructor called"<<endl;
        }
};

int main(){
    // Static allocation -> Automatically calls the destructor
    Animal suresh;
    
    // Dynamic allocation
    Animal *ramesh = new Animal;
    
    // Manually deletion 
    delete ramesh;
    
    return 0;
}
