#include<iostream>
using namespace std;
class Car{
    public:
    string name;
    void speedUp(){
        cout<<"speeding up"<<endl;

    }
};
class scorpio: public Car{

};
int main(){
    scorpio obj;
    obj.speedUp();
    return 0;
}