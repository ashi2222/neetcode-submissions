class Solution {
public:
    int solve(int curr , int prev , int n , vector<int>&nums , vector<vector<int>>&dp)
    {
        if(curr >= n)return 0;
        if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];
        int ans = 0;
        if(prev==-1 or nums[curr] > nums[prev]){
            ans = max(ans , 1 + solve(curr+1 , curr , n , nums, dp));
        }
        ans = max(ans , solve(curr+1 , prev , n , nums , dp));
        return dp[curr][prev+1]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
        return solve(0 , -1 , n , nums , dp);
    }
};
