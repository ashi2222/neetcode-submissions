class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size() == 0)return "";
        string encode = "";
        for(auto i : strs)
        {
            encode+=to_string(i.size());
            encode+=",";
        }
        encode += "#";
        for(auto i : strs)
        {
            encode += i;
        }
        return encode;
    }

    vector<string> decode(string s) {
        if(s.size() == 0)return {};
        vector<int>sizes;
        vector<string>ans;
        int i = 0;
        while(s[i]!='#')
        {
            string curr = "";
            while(s[i]!=',')
            {
                curr += s[i];
                i++;
            }
            sizes.push_back(stoi(curr));
            i++;
        }
        i++;
        for(auto j : sizes)
        {
            ans.push_back(s.substr(i,j));
            i+=j;
        }
        return ans;
    }
};
