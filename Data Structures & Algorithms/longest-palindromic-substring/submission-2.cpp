class Solution {
public:
    bool ispallindrome(string &s){
        int n = s.size();
        for(int i = 0 ; i < n/2 ; i++)
        {
            if(s[i] == s[n-i-1])continue;
            return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        // how should i make it in less time 
        int n = s.size();
        if(n==1)return s;
        int ans = 1;
        int ind=0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = n-1 ; j>i ; j--)
            {
                string temp = s.substr(i,j-i+1);
                if(ispallindrome(temp)){
                    if(ans < j-i+1){
                        ans = j-i+1;
                        ind = i;
                    }
                    break;
                }
            }
        }
        return s.substr(ind,ans);
    }
};
