class Solution {
public:
    int target;
    bool solve(int mask , int sum , vector<int>&nums , vector<int>&dp)
    {
        if(mask == ((1<<nums.size())-1))return true;
        if(dp[mask]!=-1)return dp[mask];
        int remain = target - (sum%target);
        for(int i =0 ; i < nums.size() ; i++)
        {
            if(mask & (1<<i))continue;
            if(nums[i] > remain)continue;
            bool ans = solve(mask | (1<<i) , sum + nums[i] , nums , dp);
            if(ans)return dp[mask]=true;
        }
        return dp[mask]=false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int sum =0 ;
        for(auto i : nums)
        {
            sum+=i;
        }
        if(sum%k !=0 )return false;
        sum/=k;
        target = sum;
        vector<int>dp(1<<nums.size() , -1);
        return solve(0,0,nums , dp);
    }
};