class cmp{
    public:
    bool operator()(pair<int , int>&a , pair<int,int>&b)
    {
        return a.first > b.first;
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int> , vector<pair<int,int>> , cmp>pq;
        unordered_map<int,vector<pair<int,int>>>mp;
        for(auto i : times)
        {
            mp[i[0]].push_back({i[1] , i[2]});
        }
        pq.push({0,k});
        int wt =0 ;
        vector<int>distance(n+1,1e6);
        distance[k]=0;
        while(!pq.empty())
        {
            auto i = pq.top();
            int newnode = i.second;
            pq.pop();
            for(auto j : mp[newnode])
            {
                int node = j.first;
                int dist = j.second;
                if(distance[node] > distance[newnode] + dist)
                {
                    cout<<node<<" "<<distance[node]<<" "<<distance[newnode]<<" "<<dist<<endl;
                    distance[node] = distance[newnode] + dist;
                    pq.push({distance[node], node});
                }
            }
        }
        int maxi = 0;
        for(int i = 1 ; i<=n ; i++)
        {
            if(distance[i]==1e6)return -1;
            maxi = max(maxi , distance[i]);
        }
        return maxi;

    }
};
