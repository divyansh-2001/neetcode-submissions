class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1, start = 0, end = nums.size()-1;

        while(start <= end){
            if(start == end){
                return nums[start] == target ? start : -1;
            }

            //atleast of length = 2, so compare with end;

            int mid = start + (end-start)/2;

            if(nums[mid] == target){
                return mid;
            }

            if(nums[mid] > target){
                if(nums[start] > target){
                    start = mid+1;
                } else {
                    end = mid - 1;
                }
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};
