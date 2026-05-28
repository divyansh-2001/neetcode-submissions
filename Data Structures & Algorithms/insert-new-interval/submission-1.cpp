class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        if(intervals.size() == 0){
            ans.push_back(newInterval);
            return ans;
        }

        int start = -1;
        int end = -1;

        bool overlap = false;
        bool newIntervalMerged = false;

        for(int i=0;i<intervals.size();i++){
            // check overlapping with current start and end
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if(start == -1){
                start = currStart;
                end = currEnd;
            }

            if(currStart <= end){
                end = max(end, currEnd);
                overlap = true;
            }

            if(newInterval[0] >= start && newInterval[0] <= end){
                end = max(end, newInterval[1]);
                newIntervalMerged = true;
            } else if(newInterval[1] >= start && newInterval[1] <= end){
                //do nothing.
                start = min(newInterval[0], start);
                newIntervalMerged = true;
            } else if(newInterval[1] < start && !newIntervalMerged){
                ans.push_back(newInterval);
                newIntervalMerged = true;
            }

            if(!overlap){
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
                i--;
            }

            overlap = false;
        }

        ans.push_back({start ,end});

        if(!newIntervalMerged){
            ans.push_back(newInterval);
        }

        return ans;
    }
};
