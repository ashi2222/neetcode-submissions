class Solution {
public:
    vector<int>row={-1,1,0,0};
    vector<int>col={0,0,-1,1};
    int n , m;
    void dfs(int i, int j , vector<vector<char>>&grid, vector<vector<int>>&visited)
    {
        if(i>=n or i<0 or j>=m or j<0 or visited[i][j] == 1 or grid[i][j]=='0')return;
        visited[i][j] = 1;
        for(int k = 0 ; k < 4 ; k++)
        {
            dfs(i+row[k] , j+col[k] , grid , visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size() , m = grid[0].size();
        int count = 0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j< m ; j++)
            {
                if(visited[i][j] == 0 && grid[i][j] == '1'){
                    dfs(i,j,grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
};
