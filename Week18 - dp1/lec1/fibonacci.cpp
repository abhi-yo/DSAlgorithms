// leetcode link: https://leetcode.com/problems/fibonacci-number/

class Solution
{
public:
    // int topDownSolve(int n, vector<int>&dp){
    //     // base case
    //     if(n==1||n==0){
    //         return n;
    //     }
    //     // step 3
    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }
    //     // step 2
    //     dp[n]=topDownSolve(n-1,dp)+topDownSolve(n-2,dp);
    //     return dp[n];
    // }

    // int bottomUpSolve(int n){
    //     // step 1
    //     vector<int>dp(n+1,-1);
    //     // step 2
    //     dp[0]=0;
    //     if(n==0)
    //         return dp[0];
    //     dp[1]=1;
    //     if(n==1)
    //         return dp[1];
    //     // step 3
    //     for(int i=2;i<=n;i++){
    //         dp[i]=dp[i-1]+dp[i-2];
    //     }
    //     return dp[n];
    // }

    int spaceOptSolve(int n)
    {
        // base case
        int prev2 = 0;
        int prev1 = 1;
        if (n == 0)
            return prev2;
        if (n == 1)
            return prev1;
        int curr;
        for (int i = 2; i <= n; i++)
        {
            curr = prev1 + prev2;
            // shifting
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }

    int fib(int n)
    {
        // // step 1
        // vector<int>dp(n+1,-1);
        // int ans= topDownSolve(n,dp);
        // return bottomUpSolve(n);
        return spaceOptSolve(n);
    }
};