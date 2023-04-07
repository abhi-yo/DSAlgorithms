#include<iostream>
using namespace std;
class Fruit{
    public:
    string name;
};
class Mango: public Fruit{
    public:
    int weight;
};
class Alphonso: public Mango{
    public:
    int sugarLevel;
};
int main() {
    // Create an object of the Alphonso class
    Alphonso a;
    
    // Set values for the inherited members
    a.name = "Alphonso";
    a.weight = 100;
    a.sugarLevel = 20;
    
    // Output the values of the members
    cout << "Name: " << a.name << endl;
    cout << "Weight: " << a.weight << "g" << endl;
    cout << "Sugar level: " << a.sugarLevel << "%" << endl;

    return 0;
}
