class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>ans;
        vector<vector<int>>result;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < n ; i++)
        {
            int j = i+1 ;
            int k = n-1;
            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    ans.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(sum > 0)k--;
                else j++;
            }
        }
        for(auto i : ans){
            result.push_back(i);
        }
        return result;
        
    }
};
