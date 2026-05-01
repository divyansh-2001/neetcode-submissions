class Solution {
public:
    int findMin(vector<int> &nums) {
        int start = 0;
        int end = nums.size()-1;
        int ans = -1;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(start == end || start == end - 1){
                return min(nums[start], nums[end]);
            }

            if(nums[mid] < nums[mid-1]){
                return nums[mid];
            }

            if(nums[mid] > nums[start] && nums[mid] > nums[end]){
                start = mid+1;
            } else {
                end = mid - 1;
            }
        }

        return -1;
    }
};
