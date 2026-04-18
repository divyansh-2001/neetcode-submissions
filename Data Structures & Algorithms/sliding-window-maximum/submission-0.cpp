class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int r = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        vector<int> ans;

        while(r < k-1){
            pq.push({nums[r], r});
            r++;
        }



        while(r < nums.size()){
            pq.push({nums[r], r});
            while(!pq.empty() && pq.top().second <= r - k){
                pq.pop();
            }

            r++;

            ans.push_back(pq.top().first);
        }

        return ans;
    }
};
