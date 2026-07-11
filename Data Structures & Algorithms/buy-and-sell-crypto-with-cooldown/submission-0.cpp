class Solution {
public: 
    int solve(int i , int j , int n,vector<int>&nums , vector<vector<int>>&dp)
    {
        if(i>=n)return 0;
        if(j==n)return nums[i];
        if(dp[i][j+1]!=-1)return dp[i][j+1];
        int ans =0 ;
        if(j==-1){
            ans = -nums[i] + solve(i , i+1 , n,nums , dp);
            ans = max(ans , solve(i+1 , j , n, nums , dp));
        }
        else{
            ans = nums[j] + solve(j+2 , -1 ,n, nums , dp);
            ans = max(ans , solve(i,j+1 ,n, nums , dp));
        }
        // cout<<i<<" "<<j<<" "<<ans<<endl;
        return dp[i][j+1]=ans;
    }
    int maxProfit(vector<int>& nums) {
        int  n = nums.size();
        vector<vector<int>>dp(n+2 , vector<int>(n+2 , -1));
        return solve(0 , -1 , n, nums ,dp);
    }
};