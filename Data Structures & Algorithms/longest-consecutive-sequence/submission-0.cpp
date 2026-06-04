class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1)return nums.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto i : nums)
        {
            pq.push(i);
        }
        int ans = 1;
        int count = 1;
        int num1 = pq.top();
        pq.pop();
        while(!pq.empty())
        {
            auto it  = pq.top();
            pq.pop();
            if(it == num1)continue;
            else if(it == num1 + 1){
                count++;
                ans = max(ans , count);
                num1++;
            }
            else{
                count = 1;
                num1 = it;
            }
        }
        return ans;
    }
};
