class Solution {
public:
    int solve(int l , int r , int n , vector<int>&nums , vector<vector<int>>&dp)
    {
        if(l<0 or r>=n)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        int ans =0 ;
        for(int k = l+1 ; k < r ; k++)
        {
            int prod = nums[l]*nums[k]*nums[r];
            int temp = prod + solve(l,k, n ,nums , dp) + solve(k,r,n,nums , dp);
            if(temp > ans){
                ans = temp;
            }
        }
        return dp[l][r]=ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin() , 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1 , 0));
        for(int i = n-1 ; i >= 0 ; i--)
        {
            for(int j = i+1 ; j<n ; j++)
            {
                for(int k = i+1 ; k < j ; k++)
                {
                    // cout<<
                    dp[i][j] = max(dp[i][j] , nums[i]*nums[k]*nums[j] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};
