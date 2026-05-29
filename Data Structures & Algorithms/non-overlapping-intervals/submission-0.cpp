struct comp{
    bool operator()(vector<int>& a, vector<int>& b){
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp());

        int start = intervals[0][0];
        int end = intervals[0][1];
        int ans = 0;

        for(int i=1;i<intervals.size();i++){
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if(currStart >= end){
                start = currStart;
                end = currEnd;
            } else {
                ans++;
            }
        }

        return ans;
    }
};
