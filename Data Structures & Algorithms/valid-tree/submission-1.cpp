class Solution {
public:
    bool dfs(int n , int a , vector<vector<int>>&p , 
    unordered_map<int,vector<int>>&mp , vector<int>&visited , vector<int>&permanent,
    vector<int>&parent)
    {
        visited[a]=1;
        for(auto j : mp[a])
        {
            if(j==parent[a])continue;
            if(visited[j]==1)return false;
            if(permanent[j]==0)
            {
                parent[j]=a;
                bool ans = dfs(n,j,p,mp,visited , permanent,parent);
                if(!ans)return false;
            }
        }
        visited[a]=0;
        permanent[a]=1;
        return true;
    }
    bool validTree(int a, vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int,vector<int>>mp;
        vector<int>permanent(a,0);
        for(auto i : edges)
        {
            int a = i[0];
            int b = i[1];
            mp[b].push_back(a);
            mp[a].push_back(b);
        }
        vector<int>visited(a,0);
        vector<int>parent(a,-1);
        bool ans = dfs(a,0,edges,mp,visited,permanent, parent);
        for(int i = 0 ; i< a ; i++)
        {
            if(permanent[i]==0)return false;
        }
        return ans;
    }
};
