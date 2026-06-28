class Trie{
    public:
    vector<Trie*>child;
    bool isend ;
    Trie(){
        child.resize(26 , nullptr);
        isend = false;
    }
};



class Solution {
    private:
    Trie*node = new Trie();
    Trie*ptr = node;
    vector<int>row = {-1 , 1 , 0 , 0};
    vector<int>col = {0 , 0 , -1 , 1};
public:
    void insert(string word) {
        node = ptr;
        for(auto i : word)
        {
            if(node->child[i-'a']==nullptr){
               node->child[i-'a'] = new Trie();
            }
            node = node->child[i-'a'];
        }
        node->isend = true;
    }
    void solve(Trie*node , int i , int j , string &a , int n , int m , vector<vector<char>>&board , vector<string>&ans , vector<vector<int>>&visited){
        visited[i][j] = 1;
        node = node->child[board[i][j]-'a'];
        a.push_back(board[i][j]);
        if(node->isend){
           ans.push_back(a);
           node->isend = false;
        }
        for(int k = 0 ; k < 4 ; k++){
                int r = i + row[k];
                int c = j + col[k];
                if(r>=n or r <0 or c>=m or c < 0 or visited[r][c] == 1 or node->child[board[r][c]-'a'] == nullptr)continue;
                solve(node , r ,c , a , n , m , board ,ans , visited );
            }
        
        a.pop_back();
        visited[i][j]=0;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto i : words){
            insert(i);
        }
        vector<string>ans;
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i  =0 ; i < n ; i++){
            for(int j =0 ; j < m ; j++){
                node = ptr;
                string a;
                if(node->child[board[i][j]-'a'] != nullptr){
                    solve(node , i,j,a,n,m,board,ans , visited);
                }
            }
        }
        return ans;
    }
};
