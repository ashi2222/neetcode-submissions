class Solution {
public:
    void solve(int i , string &a , string &s , vector<vector<string>>&ans , vector<string>&d)
    {
        if(i==s.size()){
                if(a.empty()){
                // cout<<"pushed"<<endl;
                ans.push_back(d);
                }
            return;
        }
        a = a + s[i];
        string dummy = a;
        reverse(a.begin() , a.end());
        if(dummy == a){
            // cout<< (a) <<endl;
            d.push_back(dummy);
            a="";
            solve(i+1 , a , s , ans , d);
            a=dummy;
            d.pop_back();
        }
        solve(i+1, dummy , s , ans , d);
    }
    vector<vector<string>> partition(string s) {
        int i = 0;
        string a="";
        vector<vector<string>>ans;
        vector<string>d;
        solve(i,a,s,ans,d);
        return ans;
    }
};
