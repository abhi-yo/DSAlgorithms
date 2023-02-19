// #include<iostream>
// #include<vector>
// using namespace std;
// int findUnique(vector<int>v){
//     int ans=0;
//     for(int i=0;i<v.size();i++){
//         ans=ans^v[i];
//     }
//     return ans;
// }
// int main(){
//     int n;
//     int size=5;
//     vector<int>v(4);
//     cout<<"Enter the elements"<<endl;
//     //taking inputs
//     for(int i=0;i<v.size();i++){
//         cin>>v[i];
//     }
//     int uniqueElement=findUnique(v);
//     cout<<"Unique element is"<<uniqueElement<<endl;
//     return 0;
// }


//CORRECTED CODE

#include<iostream>
#include<vector>
using namespace std;
int findUnique(vector<int>& v){ // Pass vector by reference to modify it
    int ans = 0;
    for(int i=0; i<v.size(); i++){
        ans = ans ^ v[i];
    }
    return ans;
}
int main(){
    int size = 5;
    vector<int> v(size);
    cout << "Enter the elements:" << endl;
    //taking inputs
    for(int i=0; i<size; i++){
        cin >> v[i];
    }
    int uniqueElement = findUnique(v);
    cout << "Unique element is " << uniqueElement << endl;
    return 0;
}
