#include<iostream>
#include<vector>
using namespace std;
int main(){

    // vector<int>v;
    // int ans=(sizeof(v)/sizeof(int));
    // cout<<ans<<endl;
    vector<int>v;
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl; //returns total elements that can be there 
    v.push_back(5); //inserting elements
    v.push_back(7);
   // v.pop_back();
  //v.pop_back();
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    //remove
    v.pop_back();
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
 

}

