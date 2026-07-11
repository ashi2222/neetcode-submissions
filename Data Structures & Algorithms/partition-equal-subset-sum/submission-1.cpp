class Solution {
public:
    int solve(int i , int sum , int n , vector<int>&nums)
    {
        if(sum == 0)return true;
        if(sum < 0)return false;
        if(i>=n)return false;
        if(solve(i+1 , sum -nums[i] ,  n , nums) or solve(i+1 , sum ,  n , nums))return true;
        return false;
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
        return solve(0,target , n , nums);
    }
};
