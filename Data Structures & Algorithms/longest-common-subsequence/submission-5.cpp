class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        // vector<vector<int>>dp(n+1 , vector<int>(m+1 , 0));
        vector<int>curr(m+1 , 0);
        vector<int>next(m+1 , 0);
        for(int i = n-1  ; i >=0 ; i--)
        {
            for(int j = m-1 ; j>= 0 ; j--)
            {
                if(text1[i] == text2[j]){
                    curr[j]= max(curr[j] , 1 + next[j+1]);
                }
                curr[j] = max({curr[j] , next[j] , curr[j+1] , next[j+1]});
            }
            next = curr;
        }
        return curr[0];
    }
};
