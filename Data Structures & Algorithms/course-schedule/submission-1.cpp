class Solution {
public:
    bool dfs(int n , int a , vector<vector<int>>&p , 
    unordered_map<int,vector<int>>&mp , vector<int>&visited , vector<int>&permanent)
    {
        visited[a]=1;
        for(auto j : mp[a])
        {
            if(visited[j]==1)return false;
            if(permanent[j]==0)
            {
                bool ans = dfs(n,j,p,mp,visited , permanent);
                if(!ans)return false;
            }
        }
        visited[a]=0;
        permanent[a]=1;
        return true;
    }
    bool canFinish(int a, vector<vector<int>>& p) {
        int n = p.size();
        unordered_map<int,vector<int>>mp;
        vector<int>permanent(a,0);
        for(auto i : p)
        {
            int a = i[0];
            int b = i[1];
            mp[b].push_back(a);
        }
        vector<int>visited(a,0);
        for(int i =0 ; i< a ; i++)
        {
            if(permanent[i] == 0)
            {
                bool ans = dfs(a,i,p,mp,visited,permanent);
                if(!ans)return false;
            }
        }
        return true;
    }
};
