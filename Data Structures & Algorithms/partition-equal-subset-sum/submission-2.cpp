class Solution {
public:
    int solve(int i , int sum , int n , vector<int>&nums , vector<vector<int>>&dp)
    {
        if(sum == 0)return true;
        if(sum < 0)return false;
        if(i>=n)return false;
        if(dp[i][sum]!=-1)return dp[i][sum];
        if(solve(i+1 , sum -nums[i] ,  n , nums,dp) or solve(i+1 , sum ,  n , nums,dp))return dp[i][sum]=true;
        return dp[i][sum]=false;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0 ;
        for(auto i : nums){
            sum+=i;
        }
        int target = 0;
        if(sum%2 == 0){
            target = sum/2;
        }
        else{
            return false;
        }
        vector<vector<int>>dp(n+1 , vector<int>(target + 1 , -1));
        return solve(0,target , n , nums,dp);
    }
};
