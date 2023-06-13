#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    pq.push(6);
    pq.push(3);
    pq.push(9);
    cout << "top element: " << pq.top() << endl; // 3

    return 0;
}