class Solution {
public:
    vector<int>row = {-1 , 1 , 0 , 0};
    vector<int>col = {0 ,0 , -1 , 1};
    int n , m;
    bool check(int i , int j , int n , int m , vector<vector<int>>&visited){
        if(i>=n or i < 0 or j>=m or j<0 or visited[i][j]==1)return false;
        return true;
    }
    bool solve(int i , int j , int k , vector<vector<char>>&board , vector<vector<int>>&visited , string &word){
        if(k==word.size())return true;
        if(!check(i,j,n,m,visited))return false;
        visited[i][j]=1;
        if(board[i][j] == word[k]){
            for(int l = 0 ; l < 4 ; l++){
                int r = i + row[l];
                int c = j + col[l];
                bool ans = solve(r,c,k+1, board , visited , word);
                if(ans)return true;
            }
        }
        visited[i][j]=0;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m= board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i = 0 ; i < n ; i++){
            for(int j =0 ; j < m ; j++){
                if(board[i][j] == word[0]){
                    bool ans = solve(i,j,0,board , visited , word);
                    if(ans)return true;
                }
            }
        }
        return false;
    }
};
