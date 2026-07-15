class Solution {
public:
    bool checkValidString(string s) {
        stack<int>s1 , s2;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i]=='(')s1.push(i);
            else if(s[i]=='*')s2.push(i);
            else{
                if(!s1.empty()){
                    s1.pop();
                    continue;
                }
                if(!s2.empty()){
                    s2.pop();
                    continue;
                }
                return false;   
            }
        }
        if(s2.size() < s1.size())return false;
        // cout<<s1.size()<<" "<<s2.size()<<endl;
        int count1 = s1.size() , count2 =0 ;
        while(!s1.empty() && !s2.empty())
        {
            if(s1.top() <= s2.top())count2++;
            s1.pop();
            s2.pop();
        }
        if(count2 >= count1)return true;
        return false;
    }
};
