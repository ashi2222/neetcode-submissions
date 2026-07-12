class Solution {
public:
    int solve(int i , int n , int target , vector<int>&nums)
    {
        if(i>=n){
            if(target == 0)return 1;
            return 0;
        }
        int ans =0 ;
        ans += solve(i+1 , n, target - nums[i] , nums );
        ans += solve(i+1 , n , target + nums[i] , nums );
        return ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0 , nums.size() , target , nums);
    }
};
