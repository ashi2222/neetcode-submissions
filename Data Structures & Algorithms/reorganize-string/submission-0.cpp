class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char,int>mp;
        for(auto i : s)
        {
            mp[i]++;
            if(mp[i] > (s.size()+1)/2)return "";
        }
        priority_queue<pair<int,char>>pq;
        for(auto i : mp){
            pq.push({i.second , i.first});
        }
        int index =0 ;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            char c = it.second;
            int count = it.first;
            // cout<<c<<" "<<count<<endl;
            while(index < n && count)
            {
                s[index]=c;
                count--;
                index+=2;
                if(index >= n)index = 1;
            }
            // if(count == 0)mp.erase(c);
        }
        return s;
    }
};