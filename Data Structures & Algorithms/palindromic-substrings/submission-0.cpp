class Solution {
public:
    int countSubstrings(string newstr) {
        int n = newstr.size();
        string s ="#";
        int count = 0;
        for(int i = 0 ; i < n ; i++)
        {
            s+=newstr[i];
            s.push_back('#');
        }
        int m = s.size();
        vector<int>radius(m,0);
        int i = 0;
        int c =0 ;
        int r = 0;
        int bc=0 , br = 0;
        while(i<m){
            if(i<r){
                radius[i] = min(radius[2*c-i] , r-i);
            }
            while(i-radius[i]-1 >=0 && i+radius[i]+1<m && s[i-radius[i]-1] == s[i+radius[i]+1]){
                radius[i]++;
            }
            if(i+radius[i] > r){
                c = i;
                r = i+radius[i];
            }
            count += (radius[i]+1)/2;
            i++;
        }
        return count;
    }
};
