class Solution {
public:
    void solve(int i , int sum ,vector<int>&nums, int &target, set<vector<int>>&st , vector<int>&a){
        if(i>=nums.size() or sum > target){
            if(sum == target){
            st.insert(a);
            }
            return;
        }
        a.push_back(nums[i]);
        solve(i ,sum + nums[i]  ,nums , target, st , a);
        a.pop_back();
        solve(i+1 ,sum , nums , target , st, a);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        set<vector<int>>st;
        int i = 0;
        int sum = 0;
        vector<vector<int>>ans;
        vector<int>a;
        solve( i,  sum , nums , target , st ,a );
        for(auto i  : st){
            ans.push_back(i);
        }
        return ans;


    }
};
