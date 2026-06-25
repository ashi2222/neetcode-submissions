class Solution {
public:
    void solve(int  i , vector<int>&nums , set<vector<int>>&st , vector<int>&a){
        if(i>=nums.size()){
            st.insert(a);
            return;
        }
        a.push_back(nums[i]);
        solve(i+1 , nums , st , a);
        a.pop_back();
        solve(i+1 , nums , st, a);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>>st;
        int i = 0;
        vector<int>a;
        solve(i  , nums , st , a);
        vector<vector<int>>ans;
        for(auto i : st){
            ans.push_back(i);
        }
        return ans;
    }
};
