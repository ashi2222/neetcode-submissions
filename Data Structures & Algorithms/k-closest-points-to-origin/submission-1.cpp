class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        unordered_map<int,vector<vector<int>>>mp;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto i : points){
            int dis = ((i[0]*i[0]) + (i[1]*i[1]));
            cout<<dis<<endl;
            mp[dis].push_back({i[0],i[1]});
        }
        for(auto i : mp){
            pq.push(i.first);
        }
        int count =0 ;
        vector<vector<int>>ans;
        while(count < k){
            auto it = pq.top();
            for(auto j : mp[it]){
                ans.push_back(j);
                count++;
                if(count >= k)break;
            }
            pq.pop();
        }
        return ans;
    }
};
