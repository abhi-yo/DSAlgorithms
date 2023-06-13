#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> pq; // it is a max heap
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);
    cout << "top element " << pq.top() << endl; // 9
    pq.pop();
    cout << pq.top() << endl;
    cout << "size: " << pq.size() << endl; // check size
    // to check is empty
    if (pq.empty())
    {
        cout << "Max heap is empty" << endl;
    }
    else
    {
        cout << "Max heap is not empty" << endl;
    }
    return 0;
}