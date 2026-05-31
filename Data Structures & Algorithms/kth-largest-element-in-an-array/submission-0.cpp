class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> pq;

        int i = 0;

        for(;i<k-1;i++){
            pq.push(nums[i]);
        }

        while(i < nums.size()){
            pq.push(nums[i]);

            while(!pq.empty() && pq.size() > k){
                pq.pop();
            }

            i++;
        }

        return pq.top();
    }
};
