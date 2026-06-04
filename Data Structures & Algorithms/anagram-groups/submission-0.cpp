class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>>mp;
        int n = strs.size();
        for(int i = 0; i < n ; i++){
            string s = strs[i];
            sort(s.begin() , s.end());
            mp[s].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto i : mp)
        {
            vector<string>b;
            for(auto j : i.second)
            {
                b.push_back(strs[j]);
            }
            ans.push_back(b);
        }
        return ans;
    }
};
