class Solution {
public:
    void solve(string &s , vector<string>&ans , int &open , int &closed , int &n)
    {
        if(open == closed && open ==n){
            ans.push_back(s);
            return;
        }
        if(open > n or closed > n)return;
        if(open < n){
            s.push_back('(');
            open++;
            solve(s , ans , open , closed , n);
            open--;
            s.pop_back();
        }
        if(open > closed){
            s.push_back(')');
            closed++;
            solve(s , ans , open , closed , n);
            closed--;
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string>ans;
        int open = 0;
        int closed = 0;
        solve(s  , ans , open , closed , n);
        return ans;
    }
};
