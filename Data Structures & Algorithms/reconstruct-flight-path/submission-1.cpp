class Solution {
public:
    void dfs(string a , vector<string>&ans , unordered_map<string , multiset<string>>&mp)
    {
        while(!mp[a].empty())
        {
            auto it = mp[a].begin();
            string next = *it;
            mp[a].erase(it);
            dfs(next , ans , mp);
        }
        ans.push_back(a);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>>mp;
        for(auto i : tickets){
            mp[i[0]].insert(i[1]);
        }
        string a = "JFK";
        vector<string>ans;
        dfs(a,ans,mp);
        reverse(ans.begin() , ans.end());
        return ans;
    }
};