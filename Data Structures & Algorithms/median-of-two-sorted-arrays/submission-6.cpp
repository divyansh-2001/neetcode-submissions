class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int middle = (m+n+1)/2;
        int start = 0;
        int end = m;

        while(start <= end){
            int mid = (start+end+1)/2;

            int l1 = mid > 0 ? nums1[mid-1]: INT_MIN;
            int r1 = mid < m ? nums1[mid]: INT_MAX;
            int l2 = middle - mid > 0 ? nums2[middle-mid-1]: INT_MIN;
            int r2 = middle - mid < n ? nums2[middle-mid]: INT_MAX;

            if(l1 <= r2 && l2 <= r1){
                if((m+n)%2 == 0){
                    return double(max(l1, l2) + min(r1, r2))/2;
                }

                return max(l1, l2);
            }

            if(l1 > r2){
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return -1;
    }
};
