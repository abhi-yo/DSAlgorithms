#include <iostream>
using namespace std;

void merge(int* arr, int s, int e) {
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    // create arrays for len1, len2
    int* left = new int[len1];
    int* right = new int[len2];
    int k = s; // initialize k to s
    // copy values
    // left
    for (int i = 0; i < len1; i++) {
        left[i] = arr[k];
        k++;
    }
    // right
    k = mid + 1;
    for (int i = 0; i < len2; i++) {
        right[i] = arr[k];
        k++;
    }
    // merge logic
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;
    while (leftIndex < len1 && rightIndex < len2) {
        if (left[leftIndex] < right[rightIndex]) {
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;  
        } else {
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }
    // copy remaining values from left array
    while (leftIndex < len1) {
        arr[mainArrayIndex++] = left[leftIndex++];
    }
    // copy remaining values from right array
    while (leftIndex < len1) {
        arr[mainArrayIndex++] = right[rightIndex++];
    }
    //delete right and left array to save space.
}

void mergeSort(int*arr, int s, int e) {
    // base case
    if (s >= e) {
        return;
    }
    int mid = s + (e - s) / 2;
    // left part sort using recursion
    mergeSort(arr, s, mid);
    // right part sort using recursion
    mergeSort(arr, mid + 1, e);
    // now merge the two sorted arrays
    merge(arr, s, e);
}

int main() {
    int arr[] = {3,1,4,2,8,12,3,4,1,100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int s = 0;
    int e = n - 1;
    mergeSort(arr, s, e);
    for (int m = 0; m < n; m++) 
        cout << arr[m] << " ";
    return 0;
}
