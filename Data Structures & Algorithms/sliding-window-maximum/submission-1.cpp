class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        for(int i=0;i<k-1;i++){
            if(dq.empty() || nums[i] > nums[dq.front()]){
                dq.push_front(i);
                continue;
            }

            dq.push_back(i);
        }

        vector<int> ans;

        for(int i=k-1;i<nums.size();i++){
            while(!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }

            if(dq.empty() || nums[i] > nums[dq.front()]){
                dq.push_front(i);
            } else {
                dq.push_back(i);
            }

            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};


// 5
// 1
// 2

// k = 3

// 3 1 5 2
