class Solution {
public:
    vector<int>row={-1,1,0,0};
    vector<int>col={0,0,-1,1};
    int n,m;
    void dfs(int i , int j , vector<vector<char>>&board , vector<vector<int>>&visited)
    {
        visited[i][j]=1;
        for(int k = 0;  k < 4 ; k++)
        {
            int r = i + row[k];
            int c = j + col[k];
            if(r>=n or r<0 or c>=m or c<0 or visited[r][c] == 1 or board[r][c] == 'X')continue;
            dfs(r,c,board,visited);
        }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i =0 ; i < n ; i++)
        {
            for(int j =0 ; j < m ; j++)
            {
                if((i==0 or i==n-1 or j==0 or j==m-1) && board[i][j]=='O')
                {
                    dfs(i,j,board,visited);
                }
            }
        }
        for(int i = 0 ; i < n ; i++)
        {
            for(int j =0 ; j < m ; j++)
            {
                if(board[i][j]=='O' && visited[i][j] == 0)
                {
                    board[i][j]='X';
                }
            }
        }
    }
};
