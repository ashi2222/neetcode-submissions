class Solution {
public:
    bool dfs(string &s , string &end , unordered_map<string,int>&mp1 , unordered_map<string,vector<string>>&mp2)
    {
        if(s==end)return true;
        mp1[s]++;
        for(auto i : mp2[s])
        {
            if(mp1.find(i) == mp1.end())
            {
                if(dfs(i , end , mp1 , mp2))return true;
            }
        }
        return false;
    }
    int ladderLength(string begin, string end, vector<string>& wlist) {
        unordered_map<string,vector<string>>mp;
        int cnt =0 ;
        for(auto i : wlist)
        {
            cnt = 0;
            for(int j = 0; j < i.size() ; j++)
            { 
                if(begin[j]!=i[j])cnt++;
                if(cnt >= 2)break;
            }
            if(cnt == 1)
            {
                mp[begin].push_back(i);
            }
        }
        int n = wlist.size();
        int m = begin.size();
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i+1 ; j < n ;j++)
            {
                cnt =0;
                for(int k = 0; k < m ; k++)
                { 
                    if(wlist[i][k]!=wlist[j][k])cnt++;
                    if(cnt >= 2)break;
                }
                if(cnt == 1)
                {
                    mp[wlist[i]].push_back(wlist[j]);
                    mp[wlist[j]].push_back(wlist[i]);
                }
            }
        }
        

        unordered_map<string,int>mp2;

        queue<string>q;
        q.push(begin);
        cnt =0 ;
        while(!q.empty())
        {
            int n = q.size();
            cnt++;
            for(int i = 0 ; i < n ; i++)
            {
                auto k = q.front();
                q.pop();
                if(k==end)return cnt;
                mp2[k]++;
                for(auto j : mp[k])
                {
                    if(mp2.find(j) == mp2.end())
                    {
                        q.push(j);
                    }
                }
            }
        }
        return 0;
    }
};
