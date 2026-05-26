class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = nums[0];

        for(int i=1;i<nums.size();i++){
            currSum += nums[i];
            if(currSum < 0){
                currSum = 0;
            } else {
                maxSum = max(maxSum, max(nums[0], currSum));
            }
        }

        return maxSum;
    }
};
