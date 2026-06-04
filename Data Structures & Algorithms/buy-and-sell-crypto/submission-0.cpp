class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans =0 ;
        int n = prices.size();
        int m = prices[0];
        if(n<=1)return 0;
        for(int i = 1 ; i < n ; i++)
        {
            int a = prices[i]-m;
            m = min(m , prices[i]);
            ans = max(ans , a);
        }
        return ans;
    }
};
