#include<iostream>
#include<string.h>

using namespace std;

class Animal{
    //state or properties
    
    private:
        int Weight;
    
    public:
        //state or properties
        int age;
        string name;
    
        //behavior
        void eat(){
            cout<<"Eating"<<endl;
        }
        void sleep(){
            cout<<"Sleeping"<<endl;
        }
        
        //using getter and setter as weight is in private access modifier.
        void setWeight(int w){
            Weight=w;
        }
        
        int getWeight(){ 
            return Weight;
        }
};

int main(){
    //creating object
    Animal ramesh;
    
    //accessing properties of object 
    ramesh.age = 12;
    ramesh.name = "Lion";
    
    cout<<"Ramesh's age: "<<ramesh.age<<endl;
    cout<<"Ramesh's name: "<<ramesh.name<<endl;
    
    ramesh.eat();
    ramesh.sleep();

    cout<<"Ramesh's weight: ";
    ramesh.setWeight(100);
    cout<<ramesh.getWeight()<<endl;

    // Dynamic Memory allocation
    Animal *suresh = new Animal;
    
    // 1st way of accessing properties using the dot operator
    (*suresh).age = 12;
    (*suresh).name = "billi";
    
    // 2nd way of accessing properties using the arrow operator
    suresh->name = "kutta";
    suresh->age = 20;
    
    suresh->eat();
    
    //deallocate memory to avoid memory leaks
    delete suresh;
    
    return 0;
}
