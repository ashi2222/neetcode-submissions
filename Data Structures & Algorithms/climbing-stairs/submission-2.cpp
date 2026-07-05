class Solution {
public:
    int solve(int n, vector<int>&dp)
    {
        if(dp[n]!=-1)return dp[n];
        if(n<=2)return n;
        return dp[n] = (solve(n-1,dp) + solve(n-2,  dp));
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};
