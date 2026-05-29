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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() <= 1){
            return intervals.size();
        }

        sort(intervals.begin(), intervals.end(), comp());
        int ans = 1;

        priority_queue<int, vector<int>, greater<>> pq;
        
        pq.push(intervals[0].end);

        for(int i=1;i<intervals.size();i++){
            int currStart = intervals[i].start;
            int currEnd = intervals[i].end;

            if(currStart >= pq.top()){
                pq.pop();
            } else {
                ans++;
            }

            pq.push(currEnd);
        }

        return pq.size();
    }
};
