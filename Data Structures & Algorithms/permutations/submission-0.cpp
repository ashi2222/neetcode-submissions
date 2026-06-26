class Solution {
public:
    void solve(int i , int n ,vector<int>&nums , vector<int>&a , vector<vector<int>>&ans , vector<int>&s){
        if(i>=n){
            ans.push_back(a);
            return;
        }
        for(int j = 0 ; j < n ; j++){
            if(s[j] == 0){
                s[j]=1;
                a.push_back(nums[j]);
                solve(i+1 , n , nums , a , ans , s);
                a.pop_back();
                s[j]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int>s(n,0);
        int i = 0; 
        vector<vector<int>>ans;
        vector<int>a;
        solve(i , n , nums , a , ans , s);
        return ans;
    }
};
