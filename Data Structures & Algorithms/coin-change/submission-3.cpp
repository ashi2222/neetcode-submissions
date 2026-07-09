class Solution {
public:
    int solve(int i , int amount , vector<int>&coins)
    {
        if(amount == 0)return 0;
        if(i>=coins.size())return INT_MAX;
        if(amount < 0)return INT_MAX;
        int ans = INT_MAX;
        int tempans = solve(i,amount-coins[i] , coins);
        int tempans1 = solve(i+1 , amount,coins);
        if(tempans != INT_MAX){
            ans = min(ans , 1+ tempans);
        }
        if(tempans1!=INT_MAX)
        {
            ans = min(ans , tempans1);
        }
        return ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int i = 0;
        int ans = solve(i,amount ,coins);
        if(ans == INT_MAX)return -1;
        return ans;
    }
};
