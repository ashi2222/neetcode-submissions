class Solution {
public:
    string minWindow(string s, string t) {
         unordered_map<int,int>mp,mp1;
        for(auto i : t)
        {
            mp[i]++;
        }
        int n = s.size();
        int m = t.size();
        if(m>n)return "";
        int count =0, start = 0 ;
        int l = 0;
        int ans = 1e9;
        string result = "";
        for(int i =0 ; i < n ; i++)
        {
            mp1[s[i]]++;
            if(mp.find(s[i])!=mp.end())
            {
            //  cout<<"1st "<<s[i]<<" "<<mp[s[i]]<<" "<<mp1[s[i]]<<endl;
             if(mp1[s[i]]<=mp[s[i]])count++;
            }
            // cout<<count<<endl;
            if(count == m)
            {
                while(mp1[s[l]] > mp[s[l]])
                {
                    // cout<<s[l]<<" "<<mp1[s[l]]<<" "<<mp[s[l]]<<endl;
                    mp1[s[l]]--;
                    l++;
                }
                if(i-l+1 < ans){
                    ans= i-l+1;
                    start = l;
                }
            }
        }
        // cout<<ans<<endl;
        if(ans==1e9)return "";
        return s.substr(start,ans);
    }
};
