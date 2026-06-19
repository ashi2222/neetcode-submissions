class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int i = 1 ;
        int j = nums.size()-1;
        // int cnt = 0 ;
        while(i<j)
        {
            int mid = (i+j)/2;
            int cnt = 0 ;
            for(int i = 0 ; i < nums.size();i++)
            {
                if(nums[i] <= mid)cnt++;
            }
            if(cnt <= mid)i=mid+1;
            else j=mid;
        }
        return i;
    }
};
