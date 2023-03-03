#include<iostream>
using namespace std;
int getLength(char name[]){
    int length=0;
    int i=0;
    while(name[i]!='\0'){
        length++;
        i++;

    }
    return length;
}
int main() {
    char name[] = "AKSHAT";
    int length = getLength(name);
    cout << "The length of the string \"" << name << "\" is " << length << endl;
    return 0;
}