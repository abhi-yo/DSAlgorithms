#include<iostream>
using namespace std;
class Car{
    public:
    int age;
    int weight;
    string name;
    void SpeedUp(){
        cout<<"Speeding up!"<<endl;
    }
};
class Scorpio: public Car{

};
class Fortuner: public Car{

};
int main(){
    Scorpio s11;
    s11.SpeedUp();

    Fortuner f11;
    f11.SpeedUp();
    return 0;
}