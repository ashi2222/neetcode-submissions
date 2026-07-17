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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin() , intervals.end() , [](Interval&a , Interval&b){
            return a.start < b.start;
        });
        if(intervals.size() == 1)return true;
        // int i = 0 ;
        for(int j = 1 ; j < intervals.size() ; j++)
        {
            if(intervals[j].start < intervals[j-1].end)return false;
        }
        return true;
    }
};
