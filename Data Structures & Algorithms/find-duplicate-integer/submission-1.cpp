class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int num = abs(nums[i]);
            int idx = abs(nums[i])-1;

            if(nums[idx] < 0){
                return num;
            } else {
                nums[idx] *= -1;
            }
        }

        return -1;
    }
};
