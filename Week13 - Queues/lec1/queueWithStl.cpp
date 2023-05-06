#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Creation
    queue<int> q;

    // Insertion
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(55);

    // Size
    cout << "Size of queue is: " << q.size() << endl;

    // Removal
    q.pop();

    cout << "Size of queue is: " << q.size() << endl;

    if (q.empty()) {
        cout << "Q is empty" << endl;
    }
    else {
        cout << "Q is not empty" << endl;
    }

    cout << "Front element is: " << q.front() << endl;

    return 0;
}
