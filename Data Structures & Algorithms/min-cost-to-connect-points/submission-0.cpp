class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
        vector<int>visited(n , 0);
        pq.push({0,0});
        int ans = 0;
        visited[0]=0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            if(visited[node])continue;
            ans += it.first;
            visited[node]=1;
            for(int i = 0; i < n ; i++)
            {
                if(!visited[i]){
                    int distance = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
                    pq.push({distance , i});
                }
            }
        }
        return ans;
    }
};