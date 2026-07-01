class Solution {
public: 
    void dfs(int i , unordered_map<int,vector<int>>&mp , int n , vector<int>&visited)
    {
        visited[i]=1;
        for(auto j : mp[i])
        {
            if(visited[j]==1)continue;
            dfs(j,mp,n,visited);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>mp;
        for(auto i : edges)
        {
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        vector<int>visited(n,0);
        int count =0 ;
        for(int i =0 ; i < n ; i++)
        {
            if(visited[i]==0)
            {
                count++;
                // cout<<"c "<<count<<endl;
                dfs(i,mp,n,visited);
            }
        }
        return count;
    }
};
