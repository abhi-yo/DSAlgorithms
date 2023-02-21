#include<iostream>
#include<vector>
using namespace std;
int lastOccurence(vector<int> arr, int target) {
    int s = 0;
    int e = arr.size() - 1;
    int ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target) {
            ans = mid; // store ans
            s = mid + 1; // right search
        }
        else if (target < arr[mid]) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans;
}
int main() {
    vector<int> arr{1, 3, 4, 4, 4, 4, 6, 7};
    int target = 4;
    int indexOfLastOcc = lastOccurence(arr, target);
    cout << "Index of last occurrence is " << indexOfLastOcc << endl;
    return 0;
}
