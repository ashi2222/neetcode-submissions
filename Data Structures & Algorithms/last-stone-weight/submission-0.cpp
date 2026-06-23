class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto i : stones){
            pq.push(i);
        }
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            if(pq.empty())return it;
            auto ij = pq.top();
            pq.pop();
            int newboy = it - ij;
            pq.push(newboy);
        }
        return 0;
    }
};
