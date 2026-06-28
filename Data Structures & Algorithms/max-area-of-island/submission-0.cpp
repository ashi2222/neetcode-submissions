class Solution {
public:
    int n , m;
    vector<int>row={-1,1,0,0};
    vector<int>col={0,0,-1,1};
    void dfs(int i , int j, vector<vector<int>>&grid , int &count)
    {
        if(i>=n or i<0 or j>=m or j<0 or grid[i][j]!=1)return;
        grid[i][j]=2;
        count++;
        for(int  k = 0 ; k < 4 ; k++)
        {
            dfs(i+row[k] , j +col[k] , grid , count);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size() , m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count = 0;
        int mac = 0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                count = 0;
                if(grid[i][j] == 1){
                    dfs(i,j,grid , count);
                    mac = max(mac,count);
                }
            }
        }
        return mac;
    }
};
