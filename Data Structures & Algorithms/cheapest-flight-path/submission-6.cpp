class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(auto i : flights)
        {
            mp[i[0]].push_back({i[1] , i[2]});
        }
        queue<pair<int,int>>q;
        q.push({src , 0});
        vector<int>dist(n , INT_MAX);
        dist[src]=0;
        // k++;
        int count = 0;
        k++;
        while(!q.empty() && count <= k)
        {
            int n = q.size();
            count++;
            for(int i =0 ; i < n ; i++)
            {
                auto it = q.front();
                int prevdist = it.second;
                q.pop();
                dist[it.first]=min(dist[it.first] , it.second);
                for(auto j : mp[it.first])
                {
                    int node = j.first;
                    int distance = j.second;
                    if(dist[node] > prevdist + distance)
                    {
                        int newdist =  prevdist + distance;
                        // cout<<it.first<<" "<<node<<" "<<dist[node]<<endl;
                        q.push({node , newdist});
                    }
                }
            }
        }
        if(dist[dst] == INT_MAX)return -1;
        return dist[dst];
    }
};
