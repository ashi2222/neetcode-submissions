class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)return nums[0];
        if(n<=2)return max(nums[0] , nums[1]);
        vector<int>dp(n+1 , 0);
        vector<int>dp2(n+1 , 0);
        dp[0]=nums[0];
        dp[1]=max(nums[0] , nums[1]);
        for(int i = 2;i < n-1 ; i++)
        {
            dp[i] = max(dp[i-1] , nums[i] + dp[i-2]);
            cout<<dp[i]<<endl;
        }
        if(n<=3)return max({nums[0] , nums[1] , nums[2]});
        dp2[1]=nums[1];
        dp2[2]=max(nums[1] , nums[2]);
        for(int j = 3 ; j < n ; j++)
        {
            dp2[j] = max(dp2[j-1] , nums[j] + dp2[j-2]);
        }
        return max(dp[n-2],dp2[n-1]);
    }
};
