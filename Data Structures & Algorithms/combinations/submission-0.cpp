class Solution {
public:
    void solve(int i , int n , int k , vector<vector<int>>&ans , vector<int>&curr )
    {
        if(k==0){
            ans.push_back(curr);
            return;
        }
        if(i>n)return;
        curr.push_back(i);
        solve(i+1 , n , k-1 , ans , curr);
        curr.pop_back();
        solve(i+1 , n , k, ans ,curr);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>curr;
        // vector<int>visited(n+1,0);
        solve(1,n,k,ans,curr);
        return ans;
    }
};