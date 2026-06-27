class Solution {
public:
    int n;
    vector<int>row;
    vector<int>col;
    vector<int>updiag;
    vector<int>lowdiag;
    void solve(int i , int n,  vector<string>&a , vector<vector<string>>&ans){
        if(i>=n){
            ans.push_back(a);
            return;
        }
        for(int j = 0; j < n ; j++){
            if(col[j] == 0 && updiag[i-j+n-1] ==0 && lowdiag[i+j]==0){
                a[i][j]='Q';
                col[j]=updiag[i-j+n-1] = lowdiag[i+j] = 1;
                solve(i+1 , n , a , ans);
                col[j]=updiag[i-j+n-1] = lowdiag[i+j] = 0;
                a[i][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        int i = 0 , j = 0;
        row.resize(n,0);
        col.resize(n,0);
        updiag.resize(2*n-1 , 0);
        lowdiag.resize(2*n-1 , 0);
        vector<vector<string>>ans;
        string s(n,'.');
        // cout<<s<<endl;
        vector<string>a(n,s);
        solve(0,n,a,ans);
        return ans;
    }
};
