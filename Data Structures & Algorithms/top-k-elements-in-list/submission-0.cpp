class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto i : nums)
        {
            mp[i]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto i : mp)
        {
            pq.push({i.second , i.first});
        }
        vector<int>ans;
        while(k)
        {
            auto it = pq.top();
            int y = it.second;
            ans.push_back(y);
            pq.pop();
            k--;
        }
        return ans;
    }
};
