class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n,1);
        vector<int>suf(n,1);
        int prod = 1;
        for(int i = 0 ; i < n-1 ; i++)
        {
            prod*=nums[i];
            pre[i+1] = prod;
        }
        prod = 1;
        for(int i =n-2 ; i>=0 ; i--)
        {
            prod*=nums[i+1];
            suf[i] = prod;
        }
        vector<int>ans(n);
        for(int i = 0 ; i < n ; i++)
        {
            if(i==0)ans[i]=suf[i];
            else if(i==n-1)ans[i]=pre[i];
            else{
                ans[i] = pre[i]*suf[i];
            }
        }
        return ans;
    }
};
