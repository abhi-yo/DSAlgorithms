#include <iostream>
#include <vector>
using namespace std;
int countPrimes(int n) {
    if (n == 0 || n == 1) {
        return 0;
    }
    vector<bool> prime(n, true);
    prime[0] = prime[1] = false;
    int ans = 0;
    for (int i = 2; i < n; i++) {
        if (prime[i]) {
            ans++;
            int j = 2 * i;
            while (j < n) {
                prime[j] = false;
                j += i;
            }
        }
    }
    return ans;
}
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int result = countPrimes(n);
    cout << "The number of prime numbers less than " << n << " is " << result << endl;
    return 0;
}
