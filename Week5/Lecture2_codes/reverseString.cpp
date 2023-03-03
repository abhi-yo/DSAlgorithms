#include<iostream>
#include<string>
using namespace std;

void reverseCharArray(char name[]) {
    int i = 0;
    int n = strlen(name);
    int j = n - 1;
    while(i <= j) {
        swap(name[i], name[j]);
        i++;
        j--;
    }
}

int main() {
    char name[] = "AKSHAT";
    reverseCharArray(name);
    cout << "The reversed string is \"" << name << "\"" << endl;
    return 0;
}
