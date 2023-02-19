#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v1{1,2,3,4,6,8};
    vector<int>v2{3,4,9,10};
    vector<int>ans;
    //outer loop on v1 vector
    for(int i=0;i<v1.size();i++){
        int element=v1[i];
        //for every element run loop on v2
        for(int j=0;j<v2.size();j++){
            if(element==v2[j]){
                ans.push_back(element);
                break;
            }
        }
    }
    for(auto value: ans){
        cout<<value<<" ";
    }
    cout<<endl;
    return 0;
}
// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//     vector<int> v1 {1, 2, 3, 4, 6, 8};
//     vector<int> v2 {3, 4, 9, 10};
//     vector<int> ans;

//     for (int i = 0; i < v1.size(); i++) {
//         int element = v1[i];

//         for (int j = 0; j < v2.size(); j++) {
//             if (element == v2[j]) {
//                 ans.push_back(element);
//                 break; // stop searching once we find the element
//             }
//         }
//     }

//     for (auto value : ans) {
//         cout << value << " ";
//     }
//     cout << endl;

//     return 0;
// }
