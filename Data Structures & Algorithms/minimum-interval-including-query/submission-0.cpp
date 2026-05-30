struct comp{
    bool operator()(vector<int>& a, vector<int>& b){
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }
};

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());
        sort(intervals.begin(), intervals.end(), comp());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        unordered_map<int,int> m;

        int idx = 0;

        for(int i=0;i<sortedQueries.size();i++){
            while(idx < intervals.size() && intervals[idx][0] <= sortedQueries[i]){
                pq.push({intervals[idx][1] - intervals[idx][0] + 1, idx});
                idx++;
            }
            
            while(!pq.empty() && intervals[pq.top().second][1] < sortedQueries[i]){
                pq.pop();
            }

            if(pq.empty()){
                m[sortedQueries[i]] = -1;
                continue;
            }

            m[sortedQueries[i]] = pq.top().first;
        }

        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(m[queries[i]]);
        }

        return ans;
    }
};
