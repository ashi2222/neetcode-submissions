class Solution {
public:
    bool solve(int i , int j , int n , int m , string&s1 , string&s2 , string&s3 , vector<vector<int>>&dp)
    {
        if(j>=m)return true;
        if(i>=n){
            if(s2.substr(j-i) == s3.substr(j))return true;
            return false;
        }
        if((j-i) >= (m-n))
        {
            if(s1.substr(i) == s3.substr(j))return true;
            return false;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i] == s3[j]){
            // cout<<i<<" "<<j<<endl;
            if(solve(i+1 , j+1 , n , m , s1 , s2 , s3 , dp))return dp[i][j] = true;
        }
        if(s2[j-i] == s3[j]){
            // cout<<j-i<<" "<<j<<endl;
            if(solve(i , j+1 , n , m , s1 , s2 , s3 ,  dp))return dp[i][j] = true;
        }
        return dp[i][j] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s3.size();
        int n = s1.size();
        int k = s2.size();
        if(n+k != m)return false;
        vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));
        return solve(0,0,n,m,s1,s2,s3 , dp);
    }
};
