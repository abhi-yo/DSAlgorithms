#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int arr[], int n, int i)
{
    int index = i;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;
    int largest = index;

    if (leftIndex < n && arr[largest] < arr[leftIndex])
    {
        largest = leftIndex;
    }

    if (rightIndex < n && arr[largest] < arr[rightIndex])
    {
        largest = rightIndex;
    }

    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        index = largest;
        heapify(arr, n, index);
    }
}
// Convert the array into a heap
void buildHeap(int arr[], int n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

int main()
{
    int arr[] = {9, 6, 5, 8, 2};
    int n = 5;
    buildHeap(arr, n);
    // Print the heapified array
    cout << "Heapified array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}