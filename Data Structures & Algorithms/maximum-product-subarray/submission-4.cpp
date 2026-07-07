class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prod = 1;
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++)
        {
            if(prod == 0){
                prod = 1;
            }
            prod*=nums[i];
            ans = max(ans , prod);
        }
        prod = 1;
        for(int i = n-1 ; i >= 0 ; i--)
        {
            if(prod == 0){
                prod = 1;
            }
            prod*=nums[i];
            ans = max(ans , prod);
        }
        return ans;
    }
};
