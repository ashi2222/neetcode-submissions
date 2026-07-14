class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int curr = 0;
        int farthest = 0 ;
        int jump = 0;
        for(int i = 0 ; i < n-1 ; i++)
        {
            int num = i + nums[i];
            farthest = max(farthest , num);
            if(i==curr){
                curr = farthest;
                jump++;
            }
        }
        return jump;
    }
};
