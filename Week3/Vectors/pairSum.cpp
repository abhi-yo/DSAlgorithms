#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v1{10,20,40,60,70};
    vector<int>sum{};
    vector<int>element{};
    for(int i=0;i<v1.size();i++){
        int element=v1[i];
        for(int j=i+1;j<v1.size();j++){
            cout<<"("<<element<<","<<v1[j]<<")"<<endl;

        }
    }
    int sum=9;
    for(int=0;i<v1.size();i++){
        for(int j=i+1;j<a.size();j++)){
            if(v1[i]+v1[j]==sum){
                cout<<"("<<v1[i]<<","<<v1[j]<<endl;
        }
    }
    
    return 0;

}