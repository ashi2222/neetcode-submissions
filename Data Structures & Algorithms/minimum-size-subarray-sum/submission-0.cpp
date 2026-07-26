class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int sum = 0;
        int ans = n+1;
        while(i<n && j<n)
        {
            sum += nums[j];
            while(i<=j && sum >= target){
                // cout<<sum<<" "<<target<<endl;
                // cout<<i<<" "<<j<<endl;
                ans = min(ans , j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        if(ans == n+1)return 0;
        return ans;
    }
};