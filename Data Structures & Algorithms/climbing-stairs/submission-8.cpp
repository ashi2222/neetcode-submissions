class Solution {
public:
    int solve(int n , vector<int>&dp)
    {
        if(n<=1)return 1;
        if(dp[n]!=-1)return dp[n];
        return solve(n-1,dp) + solve(n-2,dp);
    }
    int climbStairs(int n) {
        int prev1 = 1 ;
        int prev2 = 1;
        // dp[0]=dp[1]=1;
        for(int i = 2 ; i<=n ; i++){
            int ans =prev1 + prev2;
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
};
