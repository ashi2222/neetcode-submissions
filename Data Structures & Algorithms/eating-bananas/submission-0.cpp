class Solution {
public:
    bool solve(vector<int>&piles , int time , int h)
    {
        for(int i =0 ; i < piles.size(); i++)
        {
            int ans = piles[i]%time == 0 ? piles[i]/time : piles[i]/time + 1;
            h-=ans;
            if(h<0)return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1 , high = 1e9;
        int ans = h;
        while(low <= high)
        {
            int mid = (low + (high-low)/2);
            if(solve(piles , mid , h))
            {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};
