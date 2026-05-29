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

struct comp{
    bool operator()(Interval& a, Interval& b){
        return a.start == b.start ? a.end < b.end : a.start < b.start;
    }
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp());

        int start = intervals[0].start;
        int end = intervals[0].end;

        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start >= end){
                start = intervals[i].start;
                end = intervals[i].end;
                continue;
            }

            return false;
        }

        return true;
    }
};
