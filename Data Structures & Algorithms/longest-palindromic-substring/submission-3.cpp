class Solution {
public:
    string longestPalindrome(string newstr) {
        int n = newstr.size();
        string s ="#";
        for(int i = 0 ; i < n ; i++){
            s+=newstr[i];
            s.push_back('#');
        }
        if(n==1)return newstr;
        int bc = 0;
        int br = 0;
        int c = 0;
        int l = 0 ; 
        int r = 0;
        vector<int>radius(s.size(),0);
        radius[0]=0;
        int i = 1;
        while(i<s.size()){
            if(i<r){
                radius[i]= min(radius[2*c-i] , r-i);
            }
            while(i-radius[i]-1 >= 0 && i+radius[i]+1 < 2*n+1 && s[i-radius[i]-1] == s[i+radius[i]+1]){
                radius[i]++;
            }
            if(i+radius[i] > r){
                r = i+radius[i];
                c=i;
            }
            if(radius[i]  > br){
                br = radius[i];
                bc = i;
            }
            i++;
        }
        // cout<<bc<<endl;
        // cout<<br<<endl;
        return newstr.substr((bc-br)/2,br);
        // return newstr.substr(c-radius[i] , radius[i]);
    }
};