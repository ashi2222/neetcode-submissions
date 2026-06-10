class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int  l = 0 , h = n-1;
        int mini = nums[0];
        while(l<=h)
        {
            int mid = (l+h)/2;
            if(nums[mid] >= nums[l])
            {
                mini = min(mini , nums[l]);
                l = mid+1;
            }
            else{
                mini=min(mini,nums[mid]);
                h = mid-1;
            }
        }
        return mini;
    }
};
