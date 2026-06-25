class Solution {
public:
    void solve(int i , vector<vector<int>>&ans , vector<int>&a , int sum , vector<int>&c , int target)
    {
        if(sum == target){
            ans.push_back(a);
        }
        if(sum > target)return;

        for(int j = i ; j < c.size() ; j++){
            a.push_back(c[j]);
            solve(j , ans , a , sum+c[j] , c , target);
            a.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        int i =0 ;
        vector<vector<int>>ans;
        vector<int>a;
        int sum = 0;
        solve( i , ans , a , sum  , c , target);
        return ans;
    }
};