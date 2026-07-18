class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i = 0 ; i <= n ; i++)
        {
            int j = i;
            int sum =0;
            while(j){
                j&=(j-1);
                sum++;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
