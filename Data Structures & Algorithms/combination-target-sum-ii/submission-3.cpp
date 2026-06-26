class Solution {
public:
    void solve(int i , int sum , int &target , vector<vector<int>>&st , vector<int>&a ,  vector<int>&c){
        if(sum == target){
            st.push_back(a);
            return;
        }
        // if(index >= c.size())return;
        if(sum > target)return;

        for(int j = i ; j < c.size() ; j++){
            if( (j > i) && (c[j] == c[j-1]))continue;
            a.push_back(c[j]);
            solve(j+1 , sum + c[j] ,  target , st , a , c);
            a.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<vector<int>>st;
        sort(c.begin() , c.end());
        int i = 0;
        int sum = 0;
        vector<int>a;
        solve(i , sum , target , st , a , c);
        return st;
    }
};
