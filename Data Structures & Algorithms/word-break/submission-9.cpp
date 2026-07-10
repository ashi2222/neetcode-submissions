class Solution {
public:
    int solve(int i , int j , unordered_set<string>&st,int n, string&s , vector<vector<int>>&dp){
        if(j>=n)return false;
        if(dp[i][j]!=-1)return dp[i][j];
        if(j==n-1){
            if(st.find(s.substr(i,j-i+1))!=st.end())return dp[i][j]=true;
            return dp[i][j]=false;
        }
        if(st.find(s.substr(i,j-i+1))!=st.end()){
            if(solve(j+1 , j+1 , st,n,s,dp))return dp[i][j]=true;
        }
        return dp[i][j]=solve(i,j+1,st,n,s,dp);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        int n = s.size();
        for(auto i : wordDict){
            st.insert(i);
        }
        int i =0;
        int j =0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i =n-1 ; i >= 0 ; i--)
        {
            for(int j = n-1; j>=i   ; j--)
            {
                if(j==n-1){
                    if(st.find(s.substr(i,j-i+1))!=st.end())dp[i][j]=1;
                    else {
                        dp[i][j]=0;
                    }
                }
                else{
                    if(st.find(s.substr(i,j-i+1))!=st.end())dp[i][j]=dp[j+1][j+1];
                    if(!dp[i][j]){
                        dp[i][j]=dp[i][j+1];
                    }
                }
            }
        }
        return dp[0][0];
        // return solve(i,j,st,n,s,dp);
    }
};
