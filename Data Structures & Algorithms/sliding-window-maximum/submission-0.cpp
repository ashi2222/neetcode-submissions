class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1)return {nums[0]};
        priority_queue<pair<int,int>>pq;
        for(int i = 0; i < k ; i++)
        {
            pq.push({nums[i],i});
        }
        vector<int>ans;
        ans.push_back(pq.top().first);
        int i = k;
        int j = 0;
        while(i<n)
        {
            pq.push({nums[i],i});
            while(i-pq.top().second >= k)
            {
                // cout<<pq.top()<<endl;
                pq.pop();
            }
            i++;
            ans.push_back(pq.top().first);
        }
        return ans;  
    }
};
