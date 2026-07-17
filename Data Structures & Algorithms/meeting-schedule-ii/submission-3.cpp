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
        sort(intervals.begin() , intervals.end() , [](Interval&a , Interval&b){
            return a.start < b.start;
        });
        if(intervals.size() <= 1)return intervals.size();
        // int i = 0 ;
        int count = 1;  
        int mini = intervals[0].end;
        priority_queue<int , vector<int> , greater<int>>pq;
        pq.push(mini);                                                                                                                                                                                     ;
        for(int j = 1 ; j < intervals.size() ; j++)
        {
            if(intervals[j].start < pq.top()){
                pq.push({intervals[j].end});
            }
            else{
                if(!pq.empty()){
                pq.pop();
                }
                pq.push({intervals[j].end});
            }
        }
        return pq.size();
    }
};
