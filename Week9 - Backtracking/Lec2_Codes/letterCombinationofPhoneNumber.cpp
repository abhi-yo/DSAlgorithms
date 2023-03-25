#include <iostream>
#include <vector>
using namespace std;

void solve(vector<string>&ans,int index,string output,string digits,vector<string>&m){
    //base case
    if(index>=digits.length()){
        ans.push_back(output);
        return;
    }
    //1 case solve, baaki recursion
    int digit= digits[index]-'0'; //value char hoti hai and minus 0 krke integer bngaya.
    string value=m[digit];
    for(int i=0;i<value.length();i++){
        char ch=value[i];
        //include
        output.push_back(ch);
        //recursive call
        solve(ans,index+1,output,digits,m);
        //backtracking
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if(digits.length()==0) return ans; //empty string
    int index=0;
    string output="";
    vector<string>m(10);
    m[2]="abc";
    m[3]="def";
    m[4]="ghi";
    m[5]="jkl";
    m[6]="mno";
    m[7]="pqrs";
    m[8]="tuv";
    m[9]="wxyz";
    solve(ans,index,output,digits,m);
    return ans;
}

int main() {
    string digits = "23";
    vector<string> result = letterCombinations(digits);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
