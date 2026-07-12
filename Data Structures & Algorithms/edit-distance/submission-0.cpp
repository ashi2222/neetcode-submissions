class Solution {
public:
    int solve(int i , int j , int n , int m , string &word1 , string&word2 , vector<vector<int>>&dp)
    {
        if(i>=n && j>=m )return 0;
        if(i>=n)return (m-j);
        if(j>=m)return (n-i);
        if(dp[i][j]!=-1)return dp[i][j];
        int ans =INT_MAX ;
        if(word1[i] == word2[j]){
            // cout<<i<<" "<<j<<endl;
            ans = min(ans , solve(i+1 , j+1 , n , m ,word1 , word2 , dp));
        }
        int temp = INT_MAX;
        int temp1 = solve(i+1 , j , n , m , word1 , word2 , dp);
        int temp2 = solve(i , j+1 , n ,m , word1 , word2  ,dp);
        int temp3 = solve(i+1 , j+1 , n , m, word1 , word2 , dp);
        temp = min({temp1 , temp2 , temp3});
        if(temp!=INT_MAX){
            ans = min(ans , 1 + temp);
        }
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size() , m =word2.size();
        vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));
        return solve(0,0,n,m,word1 , word2 , dp);
    }
};