class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        vector<int>m1(n,0),m3(n,0);
        int m2 = 0;
        for(int i =0 ; i < n ; i++)
        {
            m2 = max(m2,h[i]);
            m1[i]=m2;
        }
        m2 = 0;
        for(int i = n-1 ; i>=0 ; i--)
        {
            m2 = max(m2,h[i]);
            m3[i]=m2;
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i+1 ; j<n; j++)
            {
                int area = min(m1[i] , m3[j])*(j-i);
                ans = max(ans , area);
            }
        }
        return ans;
    }
};
