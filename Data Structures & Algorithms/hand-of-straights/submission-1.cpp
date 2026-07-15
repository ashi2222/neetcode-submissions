class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        queue<int>q;
        int lc = -1 , open = 0;
        map<int,int>mp;
        for(auto i : hand)
        {
            mp[i]++;
        }
        for(auto it : mp){
            auto c = it.first;
            if((open > 0 && c > lc +1) or (open > mp[c]))return false;
            lc = c;
            q.push(mp[c]-open);
            open = mp[c];
            if(q.size() == groupSize){
                open -= q.front();
                q.pop();
            }
        }
        return open == 0;
    }
};