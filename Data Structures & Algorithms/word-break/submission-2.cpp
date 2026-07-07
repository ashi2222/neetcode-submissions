class Solution {
public:
    int solve(int i , int j , unordered_set<string>&st , string&s , int n , vector<vector<int>>&dp)
    {
        if(j>=n)return false;
        if(dp[i][j]!=-1)return dp[i][j];
        if(j==n-1)
        {
            // cout<<i<<" "<<j<<endl;
            if(st.find(s.substr(i,j-i+1)) != st.end())return dp[i][j]=true;
            return dp[i][j]=false;
        }
        if(st.find(s.substr(i,j-i+1)) != st.end()){
            // cout<<i<<" "<<j<<endl;
            if(solve(j+1 , j+1 , st , s , n,dp))return dp[i][j] = true;
        }
        return dp[i][j]=solve(i , j+1 , st ,s  , n,dp);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(auto i : wordDict){
            st.insert(i);
        }
        int n = s.size();
        int i = 0 , j = 0;
        vector<vector<int>>dp(n , vector<int>(n , -1));
        return solve(i,j,st,s,n,dp);
    }
};
