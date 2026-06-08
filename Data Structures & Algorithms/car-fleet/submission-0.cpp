class Solution {
public:
    int carFleet(int t, vector<int>& p, vector<int>& s) {
        int n = p.size();
        if(n==1)return 1;
        vector<pair<int,int>>v(n);
        for(int i =0 ; i < n ; i++)
        {
            v[i].first = p[i];
            v[i].second = s[i];
        }
        sort(v.begin() , v.end());
        double u = (double)(t-v[n-1].first)/v[n-1].second;
        int count = 1;

        // 0 3 5 8 10 => 13
        // 1 3 1 4 2
        for(int i = n-2 ; i>=0 ; i--)
        {
            double curru = (double)(t-v[i].first)/v[i].second;
            if(u < curru){
                count++;
                u = curru;
            }
        }
        return max(1,count);
    }
};
