class Solution {
public:
    void solve(int i , vector<int>&nums , vector<vector<int>>&ans){
        if(i>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j = i ; j < nums.size() ; j++){
            swap(nums[i] , nums[j]);
            solve(i+1 , nums , ans);
            swap(nums[j] , nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int i = 0; 
        vector<vector<int>>ans;
        solve(i , nums , ans );
        return ans;
    }
};
