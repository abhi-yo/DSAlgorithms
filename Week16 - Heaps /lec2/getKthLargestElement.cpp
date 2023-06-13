#include <iostream>
#include <queue>
using namespace std;

int getKthLargestElement(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    // insert k initial elements
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    // for remaining elements, push if they are greater than top
    for (int i = k; i < n; i++)
    {
        int element = arr[i];
        if (element > pq.top())
        {
            pq.pop();         // Remove the top element from the priority queue
            pq.push(element); // Push the new element
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
    int ans = getKthLargestElement(arr, n, k);
    cout << "ans: " << ans << endl;

    return 0;
}