#include <iostream>
#include <queue>
using namespace std;

int getKthSmallestElement(int arr[], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    { // insert initial k elements
        pq.push(arr[i]);
    }
    for (int i = k; i < n; i++)
    { // remaining if less than top
        int element = arr[i];
        if (element < pq.top())
        {
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;
}
int main()
{
    int arr[] = {10, 5, 20, 4, 15};
    int n = 5;
    int k = 2;
    int ans = getKthSmallestElement(arr, n, k);
    cout << "ans: " << ans << endl;

    return 0;
}