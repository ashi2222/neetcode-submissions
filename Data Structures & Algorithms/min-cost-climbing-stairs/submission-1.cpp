class Solution {
public:
    int solve(int n , vector<int>&cost)
    {
        if(n<=1)return 0;
        return min(cost[n-1] + solve(n-1,cost) , cost[n-2] + solve(n-2,cost));
    }
    int solve1(int n ,vector<int>&cost , vector<int>&dp)
    {
        if(n<=1)return 0;
        if(dp[n]!=-1)return dp[n];
        int ans = min(cost[n-1] + solve1(n-1 , cost , dp) , cost[n-2] + solve1(n-2 , cost , dp));
        return dp[n]=ans;
    }
    int solve2(vector<int>&cost){
        int n = cost.size();
        vector<int>dp(n+1 , 0);
        for(int i = 2 ; i<= n ; i++)
        {
            dp[i] = min(dp[i-1] + cost[i-1] , dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }
    int solve3(vector<int>&cost){
        int n = cost.size();
        int prev1 = 0;
        int prev2 = 0;
        for(int i = 2 ; i<= n ; i++)
        {
            int ans = min(prev1 + cost[i-1] , prev2+cost[i-2]);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // int n = cost.size();
        // vector<int>dp(n+1 , -1);
        // return solve1(n,cost,dp);
        return solve3(cost);
    }
};