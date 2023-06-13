#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class info
{
public:
    int value;
    int row;
    int col;
    info(int val, int r, int c)
    {
        value = val;
        row = r;
        col = c;
    }
};

// custom comparator
class compare
{
public:
    bool operator()(info *a, info *b)
    {
        return a->value > b->value;
    }
};

vector<int> mergeKSortedArrays(int arr[][4], int k, int n)
{
    priority_queue<info *, vector<info *>, compare> minHeap; // min heap
    // Insert the first element from each array
    for (int i = 0; i < k; i++)
    {
        info *temp = new info(arr[i][0], i, 0);
        minHeap.push(temp);
    }
    vector<int> ans;
    while (!minHeap.empty())
    {
        info *temp = minHeap.top();
        int topElement = temp->value;
        int topRow = temp->row;
        int topCol = temp->col;
        minHeap.pop();
        ans.push_back(topElement);
        if (topCol + 1 < n)
        {
            info *newInfo = new info(arr[topRow][topCol + 1], topRow, topCol + 1);
            minHeap.push(newInfo);
        }
    }
    return ans;
}

int main()
{
    int arr[][4] = {{2, 4, 6, 8}, {1, 3, 5, 7}, {0, 9, 10, 11}};
    int k = 3;
    int n = 4;
    // Call the function and store the result
    vector<int> result = mergeKSortedArrays(arr, k, n);

    // Print the merged sorted array
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
