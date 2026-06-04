class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0 ;
        int j = s.size()-1;
        while(i<j)
        {
            while(i<j && !((s[i]>='0' && s[i]<='9')or(s[i]>='a' && s[i] <= 'z')or(s[i]>='A' && s[i]<='Z')))
            {
                i++;
            }
            while(i<j && !((s[j]>='0' && s[j]<='9')or(s[j]>='a' && s[j] <= 'z')or(s[j]>='A' && s[j]<='Z')))
            {
                j--;
            }
            // cout<<s[i]<<" "<<s[j]<<endl;
            if(toupper(s[i])!=toupper(s[j]))return false;
            i++;
            j--;
        }
        return true;
    }
};
