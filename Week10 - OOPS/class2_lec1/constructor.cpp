#include<iostream>
using namespace std;

class Animal{
    int age;
    
    public:
        // Default constructor
        Animal(){
            cout<<"Default constructor called"<<endl;
        }
        
        // Parameterized constructor
        Animal(int age){
            this->age = age;
            cout<<"Parameterized constructor called"<<endl;
        }
        
        // Copy constructor
        Animal(Animal& obj){
            this->age = age;
            cout<<"Copy constructor called"<<endl;
        }
};

int main(){
    // Default constructor
    Animal suresh;
    
    // Parameterized constructor
    Animal ramesh(20);
    
    // Copy constructor
    Animal copy(suresh);
    
    return 0;
}
