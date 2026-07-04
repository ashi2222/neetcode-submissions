class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if (src == dst) return 0;
        unordered_map<int, vector<pair<int, int>>> mp;
        for (auto i : flights) {
            mp[i[0]].push_back({i[1], i[2]});
        }
        vector<int> visited(n, 0);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {src, k}});
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int dist = it.first;
            int node = it.second.first;
            if (node == dst) return dist;
            int chance = it.second.second;
            visited[node] = 1;
            if (chance < 0) continue;
            for (auto j : mp[node]) {
                int newnode = j.first;
                int newdist = j.second;
                // cout<<newnode<<endl;
                if (!visited[newnode]) {
                    // cout<<newnode<<" "<<newdist+dist<<endl;
                    pq.push({dist + newdist, {newnode, chance - 1}});
                }
            }
        }
        return -1;
    }
};
