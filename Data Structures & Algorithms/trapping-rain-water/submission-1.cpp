class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int  l =0 ;
        int  r = n-1;
        int m1 = 0, m2 =0 , ans =0 ;
        while(l < r)
        {
            m1 = max(m1 , h[l]);
            m2 = max(m2 , h[r]);
            if(m1 < m2)
            {
                ans += (m1 - h[l]);
                l++;
            }
            else{
                ans += (m2 - h[r]);
                r--;
            }
        }
        return ans;
    }
};
