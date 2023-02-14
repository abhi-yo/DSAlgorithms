// //ExtremePrint2pointer
// #include<iostream>
// using namespace std;
// int main(){
//     int arr[5]={1,2,3,4,5};
//     int size=5;
//     int start=0;
//     int end= size-1;
//     while(true){
//         if(start>end){
//             break;
//         }else{
//             cout<<arr[start]<<" ";
//             cout<<arr[end]<<" ";
//             start++;
//             end--;
//         }
//     }
//     return 0;
// }
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5; 
    int start = 0;
    int end = size - 1;
    while (start <= end) {
        cout << arr[start] << " ";
        if (start != end) { //CORRECTED
            cout << arr[end] << " ";
        }
        start++;
        end--;
    }
    return 0;
}