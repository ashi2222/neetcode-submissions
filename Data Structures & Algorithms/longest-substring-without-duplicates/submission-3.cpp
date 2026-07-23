class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int n = s.size();
        int ans =0 ;
        unordered_map<char,int>mp;
        while(i<n && j<n)
        {
            if(mp.find(s[j]) == mp.end())
            {
                mp[s[j]] =j;
                // j++;
                ans = max(ans , j-i+1);
            }
            else{
                i=max(i , mp[s[j]]+1);
                ans = max(ans , j - i+1);
                mp[s[j]] = j;
            }
            j++;
        }
        return ans;
    }
};
