class Solution {
public:
    int solve(int i , int j , int n , int m , string&text1 , string&text2  , vector<vector<int>>&dp)
    {
        if(i>=n or j>=m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = 0;
        int temp  = solve(i+1 , j+1 , n  , m , text1 , text2 , dp);
        if(text1[i] == text2[j]){
            ans = 1 + temp;
        }
        ans = max(ans , solve(i+1 , j , n , m , text1 , text2 , dp));
        ans = max(ans , solve(i,j+1 , n , m ,text1, text2 , dp));
        ans = max(ans , temp);
        return dp[i][j]=ans;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1 , vector<int>(m+1 , 0));
        for(int i = n-1  ; i >=0 ; i--)
        {
            for(int j = m-1 ; j>= 0 ; j--)
            {
                if(text1[i] == text2[j]){
                    dp[i][j]= max(dp[i][j] , 1 + dp[i+1][j+1]);
                }
                dp[i][j] = max({dp[i][j] , dp[i+1][j] , dp[i][j+1] , dp[i+1][j+1]});
            }
        }
        return dp[0][0];
    }
};
