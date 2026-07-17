class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin() , intervals.end());
        vector<int>ans;
        for(auto i : queries)
        {
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            for(auto j : intervals){
                if(j[0] <= i){
                    pq.push({j[1] - j[0]+1 , j[1]});
                }
            }
            while(!pq.empty() && i > pq.top().second){
                // cout<<pq.top().first<<" "<<pq.top().second<<endl;
                pq.pop();
            }
            if(pq.empty())ans.push_back(-1);
            else ans.push_back(pq.top().first);
        }
        return ans;
    }
};
