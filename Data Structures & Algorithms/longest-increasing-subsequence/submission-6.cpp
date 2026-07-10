class Solution {
public:
    int solve(int i , int j , vector<int>&nums, int n , vector<vector<int>>&dp)
    {
        if(j==n)return 0;
        if(dp[i+1][j]!=-1)return dp[i+1][j];
        int ans = 0;
        if(i==-1 or nums[j] > nums[i]){
            // cout<<"entered"<<endl;
            ans = max(ans , 1 + solve(j , j+1 , nums , n,dp));
        }
        ans = max(ans , solve(i,j+1 , nums , n,dp));
        // ans = max(ans , solve(i+1,j , nums , n));
        return dp[i+1][j]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return 1;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(-1,0,nums,n,dp);
    }
};
