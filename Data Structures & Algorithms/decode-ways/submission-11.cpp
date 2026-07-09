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
    int solve1(string &s)
    {
        int n = s.size();
        vector<int>dp(n+2 , 0);
        dp[n]=1;
        dp[n+1]=0;
        for(int i = n-1 ; i>=0 ; i--)
        {
            if(s[i]=='0'){
                dp[i]=0;
            }
            else if((s[i]=='1') or (i+1 < n && s[i]=='2' && s[i+1]<='6'))
            {
                dp[i]=dp[i+1]+dp[i+2];
            }
            else{
                dp[i]=dp[i+1];
            }
        }
        return dp[0];
    }
    int numDecodings(string s) {
        // int n = s.size();
        // vector<int>dp(n , -1);
        // return solve(0,n,s,dp);
        return solve1(s);
    }
};
