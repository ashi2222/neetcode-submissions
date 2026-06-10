class TimeMap {
public:
    map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp , value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>>&ans = mp[key];
        if(ans.size()==0)return "";
        

        // cout<<key<<"t"<<endl;
        int low = 0 ;
        int high = ans.size()-1;
        int a = high;
        while(low <= high)
        {
            int mid = (low + high)/2 ;
            if(ans[mid].first == timestamp){
                a=mid;
                break;
            }
            else if(ans[mid].first > timestamp){
                high = mid-1;
            }
            else {
                a = mid;
                low = mid+1;
            }
        }
        if(ans[a].first > timestamp) return "";
        // cout<<a<<" "<<ans[a].first<<" "<<ans[a].second; 
        return ans[a].second;
    }
};
