class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>pos(256,-1);
        int n = s.size();
        int ans =0 ;
        int last =0 ;
        for(int i = 0; i < n ; i++)
        {
            if(pos[s[i]]!=-1)
            {
                last = max(last,pos[s[i]]+1);
            }
            cout<<last<<" "<<pos[s[i]]<<endl;
            ans = max(ans , i - max(last, pos[s[i]]) + 1);
            pos[s[i]]=i;
        }
        return ans;
    }
};
