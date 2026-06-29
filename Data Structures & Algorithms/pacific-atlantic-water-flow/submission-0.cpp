class Solution {
public:
    vector<int>row={-1,1,0,0};
    vector<int>col={0,0,-1,1};
    int n , m;
    void dfs(int i , int j , vector<vector<int>>&h , vector<vector<int>>&visited)
    {
        for(int k =0 ; k < 4 ; k++)
        {
            int r = i + row[k];
            int c = j + col[k];
            if(r>=n or r < 0 or c>=m or c<0 or visited[r][c] == 1 or h[r][c] < h[i][j])continue;
            visited[r][c]=1;
            dfs(r,c,h,visited);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size() , m = heights[0].size();
        vector<vector<int>>visitedpacific(n,vector<int>(m,0));
        vector<vector<int>>visitedatlantic(n,vector<int>(m,0));
        vector<vector<int>>ans;
        for(int i =0 ; i < n ; i++)
        {
            if(visitedpacific[i][0] == 0){
                visitedpacific[i][0]=1;
                dfs(i,0,heights, visitedpacific);
            }
            if(visitedatlantic[i][m-1] == 0){
                visitedatlantic[i][m-1]=1;
                dfs(i,m-1,heights, visitedatlantic);
            }
        }
        for(int j = 0; j < m ; j++)
        {
            if(visitedpacific[0][j] == 0)
            {
                visitedpacific[0][j]=1;
                dfs(0,j,heights, visitedpacific);
            }
            if(visitedatlantic[n-1][j] == 0)
            {
                visitedatlantic[n-1][j]=1;
                dfs(n-1,j,heights, visitedatlantic);
            }
        }

        for(int i =0 ; i< n ; i++)
        {
            for(int j =0 ; j< m ;j++)
            {
                cout<<i<<" "<<j<<" "<<visitedpacific[i][j]<<" "<<visitedatlantic[i][j]<<endl;
                if(visitedpacific[i][j] == 1 && visitedatlantic[i][j] == 1)
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
        
    }
};
