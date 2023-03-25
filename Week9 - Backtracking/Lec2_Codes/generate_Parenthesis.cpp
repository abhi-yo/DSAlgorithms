#include <iostream>
#include <vector>
using namespace std;

void solve(vector<string>& ans, int n, int open, int close, string output) {
    //base case
    if (open == 0 && close == 0) {
        ans.push_back(output);
        return;
    }
    
    //include open bracket
    if (open > 0) {
        output.push_back('(');
        solve(ans, n, open-1, close, output);
        //backtracking
        output.pop_back();
    }
    
    //include close bracket
    if (close > open) {
        output.push_back(')');
        solve(ans, n, open, close-1, output);
        //backtracking
        output.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    int open = n;
    int close = n;
    solve(ans, n, open, close, "");
    return ans;
}

int main() {
    int n = 3;
    vector<string> ans = generateParenthesis(n);
    for (string s : ans) {
        cout << s << " ";
    }
    return 0;
}
