class CountSquares {
public:
    map<pair<int,int> , int>mp;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int a = point[0] , b = point[1];
        int ans = 0;
        for(auto i : mp){
            int c = i.first.first;
            int d = i.first.second;
            if(a!=c or b==d)continue;
            int e = d-b;
            ans += mp[{c,d}]*mp[{c+e,d}]*mp[{a+e,b}];
            ans += mp[{c,d}]*mp[{c-e,d}]*mp[{a-e,b}];
        }
        return ans;
    }
};
