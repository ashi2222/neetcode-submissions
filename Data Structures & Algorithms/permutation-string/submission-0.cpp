class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(m<n)return false;
        vector<int>mp(26,0),mp1(26,0);
        for(int i = 0 ; i < n ; i++){
            mp[s1[i]-'a']++;
            mp1[s2[i]-'a']++;
        }
        int j = n;
        int i =0;
        if(mp==mp1)return true;
        while(j<m)
        {
            mp1[s2[i]-'a']--;
            mp1[s2[j]-'a']++;
            // cout<<s2[i]<<" "<<mp1[s2[i]]<<" ";
            // cout<<s2[j]<<" "<<mp1[s2[j]]<<endl;
            if(mp==mp1)return true;
            j++;
            i++;
        }
        return false;
    }
};
