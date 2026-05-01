class Solution {
private:
    int getPivot(vector<int>& nums){
        int start = 0, end = nums.size()-1;
        while(start <= end){
            if(start == end){           // length 1
                return start;
            }

            if(end == start + 1){       // length 2
                return nums[end] < nums[start] ? end : start;
            }

            int mid = start + (end-start)/2;

            if(mid > 0){        // length of 3 atleast
                if(nums[mid] < nums[mid-1]){
                    return mid;
                }

                if(nums[mid] > nums[end]){
                    start = mid + 1;
                } else { 
                    end = mid - 1;
                }
            }
        }

        return -1;
    }

    int find(int start, int end, vector<int>& nums, int target){
        while(start <= end){
            int mid = start + (end-start)/2;

            if(nums[mid] == target){
                return mid;
            }

            if(nums[mid] > target){
                end = mid - 1;
            } else { 
                start = mid + 1;
            }
        }

        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;

        int pivot = getPivot(nums);

        if(pivot == 0){
            cout<<"hell"<<endl;
            return find(0, nums.size()-1, nums, target);
        }

        int a = find(0, pivot-1, nums, target);
        if(a!=-1){
            return a;
        }

        return find(pivot, nums.size()-1, nums, target);
    }
};
