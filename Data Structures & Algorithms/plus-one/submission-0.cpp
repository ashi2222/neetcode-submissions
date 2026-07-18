class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ans;
        int count = 1;
        int val = 0;
        int n = digits.size();
        for(int i = n-1 ; i>=0 ; i--)
        {
            val = digits[i]  + count;
            count = val/10;
            val%=10;
            ans.push_back(val);
        }
        while(count){
            val = count%10;
            count/=10;
            ans.push_back(val);
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};
