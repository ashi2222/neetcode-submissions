class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin() , intervals.end());
        vector<int>ans(queries.size());
        vector<vector<int>>q;
        for(int i = 0 ; i < queries.size() ; i++)
        {
            q.push_back({queries[i] , i});
        }
        sort(q.begin() , q.end());
        int j = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it : q){
            int i = it[0];
            while(j<intervals.size() && intervals[j][0] <= i){
                pq.push({intervals[j][1] - intervals[j][0] + 1, intervals[j][1]});
                j++;
            }
            
            while(!pq.empty() && i > pq.top().second){
                // cout<<pq.top().first<<" "<<pq.top().second<<endl;
                pq.pop();
            }
            if(pq.empty())ans[it[1]]=-1;
            else ans[it[1]]=pq.top().first;
        }
        return ans;
    }
};
