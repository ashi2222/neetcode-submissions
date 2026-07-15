class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        multiset<int>st;
        for(auto i : hand)
        {
            st.insert(i);
        }
        while(!st.empty()){
            int val = *(st.begin());
            for(int next = val ; next < val + groupSize ; next++)
            {
                auto j = st.find(next);
                if(j == st.end())return false;
                st.erase(j);
            }
        }
        return true;
    }
};
