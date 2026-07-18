class Solution {
public:
    bool solve(int n , unordered_map<int,int>&mp)
    {
        if(n==1)return true;
        if(mp.find(n) == mp.end()){
            mp[n]++;
            int sum = 0 ;
            while(n){
                sum += pow(n%10 , 2);
                n/=10;
            }
            return solve(sum , mp);
        }
        return false;
    }
    bool isHappy(int n) {
        unordered_map<int,int>mp;
        return solve(n,mp);
    }
};
