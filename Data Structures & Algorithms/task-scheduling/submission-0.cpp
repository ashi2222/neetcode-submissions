class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int>mp;
        for(auto i : tasks){
            mp[i-'A']++;
        }
        priority_queue<int>pq;
        for(auto i : mp){
            pq.push(i.second);
        }
        queue<pair<int,int>>q;
        int count = 0;
        while((!pq.empty()) or (!q.empty())){
            count++;
            if(!pq.empty()){
                auto it = pq.top();
                pq.pop();
                it--;
                if(it > 0){
                    q.push({it , count + n});
                }
            }
            if(!q.empty() && (count == (q.front().second))){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return count;
    }
};
