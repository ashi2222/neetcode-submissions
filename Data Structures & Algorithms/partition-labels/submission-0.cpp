class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>dist(26,-1);
        for(int i = 0; i < s.size() ; i++)
        {
            dist[s[i]-'a']=i;
        }
        int lastpos = 0;
        int size = 0;
        vector<int>ans;
        int firstpos = 0;
        for(int i = 0; i < s.size() ; i++)
        {
            lastpos = max(lastpos , dist[s[i]-'a']);
            if(lastpos==i){
                ans.push_back(i-firstpos + 1);
                firstpos = i+1;
            }
        }
        return ans;
    }
};
