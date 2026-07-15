class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        unordered_map<int,int>mp3;
        for(auto i : triplets){
            if(i[0] > target[0] or i[1] > target[1] or i[2] > target[2])continue;
            mp1[i[0]]++;
            mp2[i[1]]++;
            mp3[i[2]]++;
        }
        if(mp1.find(target[0]) == mp1.end() or mp2.find(target[1]) == mp2.end() or mp3.find(target[2]) == mp3.end())return false;
        return true;
    }
};
