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
        vector<int>dp(n+1 , 0);
        dp[n]=1;
        for(int i = n-1 ; i >= 0; i--)
        {
            for(int j = n -1 ; j  >= i ; j--)
            {
                if(st.find(s.substr(i,j-i+1)) != st.end()){
                    dp[i] = dp[j+1];
                    if(dp[i])break;
                }
            }
        }
        return dp[0];
    }
};
