class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int>m1(n,0),m2(n,0);
        int m3 = 0;
        for(int i =0 ; i < n ; i++)
        {
            m3 = max(m3 ,h[i]);
            m1[i]=m3;
        }
        m3 = 0;
        for(int i = n-1 ; i>=0 ; i--)
        {
            m3 = max(m3 ,h[i]);
            m2[i]=m3;
        }
        int ans = 0;
        for(int i = 0; i < n ;i++)
        {
            int a = min(m1[i] , m2[i]);
            if(a > h[i])
            {
                ans += (a-h[i]);
            }
        }
        return ans;
    }
};
