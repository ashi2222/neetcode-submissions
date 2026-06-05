class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int>mp(26,0);
        int a = 0;
        int j = 0 ;
        int ans = 0;
        for(int i = 0; i < n ; i++)
        {
            mp[s[i]-'A']++;
            a=max(a,mp[s[i]-'A']);
            while((i-j+1)-a>k)
            {
                mp[s[j]-'A']--;
                j++;
            }
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};
