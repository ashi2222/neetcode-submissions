class Solution {
public:
    int search(vector<int>& nums, int target) {
         auto it = lower_bound(nums.begin() , nums.end() , target);
        if(it!=nums.end()){
            int ind = it - nums.begin();
            if(nums[ind] == target)return ind;
        }
        return -1;
    }
};
