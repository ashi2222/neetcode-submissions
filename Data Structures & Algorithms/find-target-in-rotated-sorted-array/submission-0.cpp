class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int  l = 0 , h = n-1;
        int mini = nums[0];
        while(l<=h)
        {
            int mid = (l+h)/2;
            // cout<<l<<" "<<h<<" "<<mid<<endl;
            if(nums[mid] == target)return mid;
            else if(nums[mid] >= nums[l])
            {
                if(nums[mid] >= target && target >= nums[l]){
                    h= mid;
                }
                else{
                    l = mid+1;
                }
            }
            else{
                if(nums[mid] <= target && target <= nums[h])
                {
                   l=mid;
                }
                else{
                    h = mid-1;
                }
            }
        }
        return -1;
    }
};
