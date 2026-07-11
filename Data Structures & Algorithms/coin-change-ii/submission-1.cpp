class Solution {
public:
    int solve(int i , int amount ,int n, vector<int>&coins , vector<vector<int>>&dp)
    {
        if(amount == 0)return 1;
        if(amount < 0)return 0;
        if(dp[i][amount]!=-1)return dp[i][amount];
        // if(i>=n)return 0;
        int ans =0;
        for(int j = i ; j < n ; j++)
        {
            ans += solve(j , amount-coins[j] , n , coins,dp);
        }
        return dp[i][amount]=ans;

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        sort(coins.begin() , coins.end());
        vector<vector<int>>dp(n+1 , vector<int>(amount + 1 , -1));
        return solve(0,amount ,n, coins ,  dp);
    }
};
