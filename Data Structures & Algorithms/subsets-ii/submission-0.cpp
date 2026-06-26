class Solution {
public:
    void solve(int index , vector<int>&nums , vector<int>&a , vector<vector<int>>&ans)
    {
        ans.push_back(a);
        if(index >= nums.size()){
            return;
        }
        for(int j = index ; j < nums.size() ; j++){
            if(j>index && nums[j] == nums[j-1])continue;
            a.push_back(nums[j]);
            solve(j+1 , nums , a , ans);
            a.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>>ans;
        int i = 0 ;
        vector<int>a;
        solve(i , nums , a, ans);
        return ans;
    }
};
