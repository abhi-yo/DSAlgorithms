#include <iostream>
using namespace std;
// class Animal{
//     public:
//     int age;
//     int weight;
//     void eat(){
//         cout<<"Eating"<<endl;
//     }
// };

// class for perfect encapsulation
class Animal{
    private:
    int age;
    int weight;
    public:
    void eat(){
        cout<<"Eating"<<endl;
    }
    int getage(){
        return this->age;
    }
    void setAge(int age){
        this->age=age;
    }
};
int main(){
    cout<<"Hello World!"<<endl;
    return 0;
}