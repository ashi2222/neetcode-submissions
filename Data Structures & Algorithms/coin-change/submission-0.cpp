class Solution {
public:
    int solve(int ind , int sum , int count , vector<int>&coins , int amount){
        if(sum == amount)return count;
        if(sum > amount)return INT_MAX;
        int ans = INT_MAX;
        for(int j = ind ; j < coins.size(); j++)
        {
            ans = min(ans , solve( j , sum + coins[j] ,  count+1 , coins , amount));
        }
        return ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int sum = 0;
        int count = 0;
        int ind = 0;
        int ans = solve(ind , sum , count , coins , amount);
        if(ans == INT_MAX)return -1;
        return ans;
    }
};
