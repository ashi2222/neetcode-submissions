class Solution {
public:
    bool solve(int i , int j , string&s , string&p , int n , int m , vector<vector<int>>&dp)
    {
        if(i==n){
            while(j+1<m && p[j+1]=='*'){
                j+=2;
            }
            return j>=m;
        }
        if(i>=n)return false;
        if(j>=m)return false;
        if(dp[i][j]!=-1)return dp[i][j];
        bool charmatch = (s[i]==p[j] or p[j] == '.');
        if(charmatch){
            if(solve(i+1 , j+1 , s ,p , n , m , dp))return dp[i][j] = true;
        }
        if(j+1 < m && p[j+1] == '*'){
            if(charmatch){
            bool ans = solve(i+1 , j , s , p , n , m , dp) or solve(i, j+2 , s , p , n , m , dp);
            if(ans)return dp[i][j] = ans;
            }
            return dp[i][j] = solve(i, j+2 , s , p , n , m , dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size() , vector<int>(p.size() , -1));
        return solve(0,0,s,p,s.size() , p.size() , dp);
    }
};
