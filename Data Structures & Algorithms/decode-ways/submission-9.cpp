class Solution {
public:
    int solve(int i , int n , string &s , vector<int>&dp)
    {
        if(i>=n)return 1;
        if(dp[i]!=-1)return dp[i];
        if(s[i]=='0')return dp[i]=0;
        if(i+1 < n && ((s[i]=='2' && s[i+1]<='6') or (s[i]<'2'))){
            return dp[i]=solve(i+1 , n , s,dp) + solve(i+2 ,n,s,dp);
        }
        return dp[i]=solve(i+1 , n , s,dp) ;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n , -1);
        return solve(0,n,s,dp);
    }
};
