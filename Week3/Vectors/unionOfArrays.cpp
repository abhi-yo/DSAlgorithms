// This is not he perfect code as it will print :
// [1,2,3,4]U[1,2,6,7] = [1,2,3,4,1,2,6,7] which does not follow union definition.
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> ans;
    int v1[]={1,3,5,7,9};
    int sizev1=5;
    int v2[]={2,4,6,8,1,4,5};
    int sizev2=8;
    for(int i=0;i<sizev1;i++){
        ans.push_back(v1[i]);
    }
    for(int i=0;i<sizev2;i++){
        ans.push_back(v2[i]);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";

    }
    return 0;

}