class Solution {
public:
    vector<int>row={-1,1,0,0};
    vector<int>col={0,0,-1,1};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>>visited(n , vector<int>(grid[0].size() ,0));
        visited[0][0]=1;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int i = it.second.first;
            int j = it.second.second;
            if(i==n-1 && j==n-1)return wt;
            for(int k = 0 ; k < 4 ; k++)
            {
                int r = i + row[k];
                int c = j + col[k];
                if(r>=n or r<0 or c>=m or c<0 or visited[r][c] == 1)continue;
                visited[r][c]=1;
                int distance = max(grid[r][c] , wt);
                pq.push({distance , {r,c}});
            }
        }
    }
};
