class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int l = 0 , r =n-1;
        int ans = 0;
        while(l<r)
        {
            int area = (r-l)*(min(h[r] , h[l]));
            ans = max(area , ans );
            if(h[l] < h[r])l++;
            else r--;
        }
        return ans;
    }
};
