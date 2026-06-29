struct cmp {
    bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b)  {
        return a.first > b.first; // Min-heap behavior based on 'first'
    }
};

class Solution {
public:
    vector<int>row={-1,1,0,0};
    vector<int>col={0,0,-1,1};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, cmp>pq;
        int n = grid.size() , m=grid[0].size();
        for(int i = 0; i < n  ;i++)
        {
            for(int j =0 ; j < m ; j++)
            {
                if(grid[i][j] == 0){
                    pq.push({0,{i,j}});
                }
            }
        }

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int d = it.first;
            int i = it.second.first;
            int j = it.second.second;
            for(int k =0 ; k<4 ; k++)
            {
                int r = i + row[k];
                int c = j + col[k];
                if(r>=n or r<0 or c>=m or c<0 or grid[r][c]==-1)continue;
                if(grid[r][c] > (d+1))
                {
                    grid[r][c] = d+1;
                    pq.push({grid[r][c] , {r,c}});
                }
            }
        }
    }
};
