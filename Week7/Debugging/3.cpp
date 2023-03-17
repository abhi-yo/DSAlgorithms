#include <iostream>
using namespace std;
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];//fixed swap with minimum element
        arr[i] = temp;
    }
}
int main() {
    int arr[5] = { 2, 14, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    for(int m=0;m<n;m++){
        cout<<arr[m]<<" ";
    }
}

