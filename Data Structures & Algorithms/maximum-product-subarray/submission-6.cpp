class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre = 1;
        int suf = 1;
        int ans = nums[0];
        int n = nums.size();
        for(int i = 0;  i<n ; i++){
            if(pre==0)pre=1;
            if(suf==0)suf=1;
            pre*=nums[i];
            suf*=nums[n-i-1];
            ans = max({ans , pre , suf});
        } 
        return ans;       
    }
};
