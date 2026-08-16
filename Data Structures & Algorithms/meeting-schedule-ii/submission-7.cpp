/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int>first , second;
        int n = intervals.size();
        for(int i = 0 ; i < n ; i++)
        {
        first.push_back(intervals[i].start);
        second.push_back(intervals[i].end);
        }
        sort(first.begin() , first.end());
        sort(second.begin() , second.end());
        int i = 0;
        int j = 0;
        int ans = 0 ;
        int count = 0;
        while(i<n && j<n)
        {
            while(i<n && second[j] > first[i])
            {
                count++;
                ans = max(count , ans);
                i++;
            }
            count = max(0 , count-1) ;
            j++;
        }
        return ans;
    }
};
