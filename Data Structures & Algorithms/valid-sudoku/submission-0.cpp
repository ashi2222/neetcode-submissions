class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9],col[9][9],cross[9][9];
        for(int i = 0 ; i< 9 ; i++)
        {
            for(int j = 0 ; j < 9 ; j++)
            {
                if(board[i][j]!='.')
                {
                    int num = board[i][j]-'1';
                    int crossi = (i/3)*3 + j/3;
                    if(row[i][num] or col[j][num] or cross[crossi][num])return false;
                    row[i][num] = col[j][num] = cross[crossi][num]=true;
                }
            }
        }
        return true;
    }
};
