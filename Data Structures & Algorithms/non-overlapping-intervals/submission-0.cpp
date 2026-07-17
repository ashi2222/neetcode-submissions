class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int i = 0;
        int n = intervals.size();
        if(n==1)return 0;
        sort(intervals.begin() , intervals.end() , 
        [](vector<int>&a , vector<int>&b)
        {
            return a[1]  < b[1];
        });
        int j = 1;
        // vector<vector<int>>ans;
        vector<int>a={intervals[0][0] , intervals[0][1]};
        int count = 0;
        while(i<n && j<n)
        {
            j = i+1;
            a= {intervals[i][0] , intervals[i][1]};
            while(j<n && intervals[j][0] < a[1]){
                // a = { min(intervals[j][0] , a[0]) , max(intervals[j][1] , a[1])};
                count++;
                j++;
            }
            // cout<<i<<" "<<j<<endl;
            // count++;
            i=j;
        }
        return count;
    }
};