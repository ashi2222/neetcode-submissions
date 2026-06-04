class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int l = 1 , r = 1;
        vector<int>ans(n,1);
        for(int i  =0 ; i <  n ;i++)
        {
            ans[i]*=l;
            ans[n-i-1]*=r;
            l*=nums[i];
            r*=nums[n-i-1];
        }
        return ans;
    }
};
