class Solution {
public:
    int possible(vector<int>&piles , int mid , int h)
    {
        int count = 0;
        for(auto i  : piles)
        {
            count += (i/mid);
            if((i%mid) != 0)count++;
            if(count > h)return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int high = piles[0];
        for(auto  i : piles)
        {
            high = max(i , high);
        }
        int low = 1;
        int ans = high;
        while(low <= high)
        {
            int mid = (low + (high-low)/2);
            if(possible(piles , mid , h))
            {
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};