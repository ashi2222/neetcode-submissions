class Solution {
public:
    bool solve(vector<int>&a , int low , int high , int target){
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(a[mid] == target)return true;
            else if(a[mid] > target)high = mid-1;
            else low = mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int n = m.size();
        int n1 = m[0].size();
        int r1 = 0, r2 = n-1, c1 = 0 , c2 = n1-1;
        if(target < m[0][0])return false;
        while(r1<=r2)
        {
            int midr = (r2+r1)/2 ;
            int midc = (c1+c2)/2;
            if(m[midr][midc] == target)return true;
            else if(m[midr][midc] > target){
                if(m[midr][0]<= target && target < m[midr][midc])
                {
                    return solve(m[midr] , 0 , midc , target);
                }
                else{
                    r2 = midr-1;
                    c2 = n1-1;
                }
            }
            else{
                if(m[midr][midc]<= target && target <= m[midr][n1-1])
                {
                    return solve(m[midr] , midc , n1-1 , target);
                }
                else{
                    r1 = midr+1;
                    c1 = 0;
                }
            }
        }
        return false;

    }
};
