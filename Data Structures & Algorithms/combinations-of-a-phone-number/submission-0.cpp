class Solution {
public:
    unordered_map<int , string>mp;
    void mapping(){
    mp[2]="abc";
    mp[3]="def";
    mp[4]="ghi";
    mp[5]="jkl";
    mp[6]="mno";
    mp[7]="pqrs";
    mp[8]="tuv";
    mp[9]="wxyz";}
    void solve(int i , int n , string &a , vector<string>&ans , string &digits){
        if(i>=n){
            // cout<<a<<endl;
            ans.push_back(a);
            return;
        }
        for(int j = 0 ; j < mp[digits[i]-'0'].size() ; j++){
            a.push_back(mp[digits[i]-'0'][j]);
            solve(i+1,n,a,ans,digits);
            a.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        mapping();
        string a ;
        vector<string>ans;
        int i =0 ;
        int n = digits.size();
        if(n==0)return ans;
        solve(i,n,a,ans , digits);
        return ans;
    }
};
