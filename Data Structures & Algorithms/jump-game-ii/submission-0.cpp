class Solution {
public:
    int jump(vector<int>& nums) {
        int curr = 0, ans = INT_MAX, maxReached = 0;
        vector<int> jumps(nums.size(), 0);

        while(curr < nums.size()){
            int reach = curr + nums[curr];
            if(reach >= nums.size()-1){
                return jumps[curr] + 1;
            }

            for(int i=maxReached+1;i<=reach && i < nums.size();i++){
                jumps[i] = jumps[curr] + 1;
            }

            maxReached = max(reach, maxReached);
            curr++;
        }

        return jumps[nums.size()-1];
    }
};
