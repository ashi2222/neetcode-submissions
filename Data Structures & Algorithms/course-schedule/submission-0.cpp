class Solution {
public:
    bool dfs(int n , int a , vector<vector<int>>&p , unordered_map<int,vector<int>>&mp , vector<int>&visited)
    {
        visited[a]=1;
        for(auto j : mp[a])
        {
            if(visited[j] == 1)return false;
            bool ans = dfs(n,j,p,mp,visited);
            if(!ans)return false;
        }
        visited[a]=0;
        return true;
    }
    bool canFinish(int a, vector<vector<int>>& p) {
        int n = p.size();
        unordered_map<int,vector<int>>mp;
        for(auto i : p)
        {
            int a = i[0];
            int b = i[1];
            mp[a].push_back(b);
        }
        vector<int>visited(a,0);
        for(int i =0 ; i< n ; i++)
        {
            if(visited[i] == 0)
            {
                bool ans = dfs(a,i,p,mp,visited);
                if(!ans)return false;
            }
        }
        return true;
    }
};
