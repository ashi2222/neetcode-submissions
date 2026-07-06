class Solution {
public:
    int solve(int ind , int sum , vector<int>&coins , int amount){
        if(sum == amount)return 0;
        if(sum > amount)return INT_MAX;
        int ans = INT_MAX;
        for(int j = ind ; j < coins.size(); j++)
        {
            
            int newans = solve( j , sum + coins[j], coins , amount);
            // cout<<newans<<endl;
            if(newans >= INT_MAX-1)continue;
            ans = min(ans , 1 + newans);
        }
        return ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int sum = 0;
        int count = 0;
        int ind = 0;
        int ans = solve(ind , sum  , coins , amount);
        if(ans == INT_MAX)return -1;
        return ans;
    }
};
