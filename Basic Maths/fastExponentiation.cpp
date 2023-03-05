#include<iostream>
using namespace std;

// function to compute a^b using fast exponentiation
int fastExponentiation(int a, int b) {
    int ans = 1;
    while (b > 0) {
        // if b is odd, multiply ans by a
        if (b & 1) {
            ans = ans * a;
        }
        // square a and divide b by 2
        a = a * a;
        b >>= 1;
    }
    return ans;
}

int main() {
    int a = 2;
    int b = 4;
    int result = fastExponentiation(a, b);
    cout << a << "^" << b << " = " << result << endl;
    return 0;
}
