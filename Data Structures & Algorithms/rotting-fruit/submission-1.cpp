class Solution {
public:
    vector<int>row={-1,1,0,0};
    vector<int>col={0,0,-1,1};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n = grid.size() , m= grid[0].size();
        for(int i = 0; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
            }
        }

        int time =0 ;
        while(!q.empty())
        {
            time++;
            int z = q.size();
            for(int i =0 ; i < z ; i++)
            {
                auto it = q.front();
                q.pop();
                // cout<<it.first<<" "<<it.second<<endl;
                for(int k = 0 ; k < 4 ; k++)
                {
                    int r = it.first + row[k];
                    int c = it.second + col[k];
                    // cout<<r<<" ashu "<<c<<endl;
                    if(r>=n or r<0 or c>=m or c<0 or grid[r][c] != 1)continue;
                    // cout<<r<<" "<<c<<endl;
                    grid[r][c]=2;
                    q.push({r,c});
                }
            }
        }
        for(int i =0 ; i < n ; i++)
        {
            for(int j =0 ; j < m ; j++)
            {
                if(grid[i][j] == 1)return -1;
            }
        }
        return (time-1 > 0) ? (time - 1) : 0;
    }
};
