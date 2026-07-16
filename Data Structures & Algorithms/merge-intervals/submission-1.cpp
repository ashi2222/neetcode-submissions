class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int i = 0;
        int n = intervals.size();
        if(n==1)return intervals;
        sort(intervals.begin() , intervals.end());
        int j = i+1;
        // vector<vector<int>>ans;
        vector<int>a={intervals[0][0] , intervals[0][1]};
        while(i<n && j<n)
        {
            j = i+1;
            a= {intervals[i][0] , intervals[i][1]};
            while(j<n && intervals[j][0] <= a[1]){
                a = { min(intervals[j][0] , a[0]) , max(intervals[j][1] , a[1])};
                j++;
            }
            // cout<<i<<" "<<j<<endl;
            ans.push_back(a);
            i=j;
        }
        return ans;
    }
};
