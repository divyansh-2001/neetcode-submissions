// 1 2 3 4 5
// 6 7 8 9 10

// middle = 5
// m = 5, n =. 5
// start = 0, end = 5

// lmid = 2
// rmid = 3






class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int middle = ( m + n + 1 ) / 2;

        int start = 0;
        int end = nums1.size();

        while(start <= end){
            int lmid = (start + end + 1)/2;
            int rmid = middle - lmid;

            int l1 = lmid - 1 >= 0 ? nums1[lmid-1] : INT_MIN;
            int r1 = lmid < nums1.size() ? nums1[lmid] : INT_MAX;
            int l2 = rmid - 1 >= 0 ? nums2[rmid-1] : INT_MIN;
            int r2 = rmid < nums2.size() ? nums2[rmid] : INT_MAX;

            // cout<<l1<<" "<<r1<<endl;
            // cout<<l2<<" "<<r2<<endl;

            if(l1 <= r2 && l2 <= r1){
                if((m+n)%2 == 0){
                    return double(max(l1, l2) + min(r1, r2))/2;
                }

                return max(l1, l2);
            }

            if(l1 > r2){
                end = lmid - 1;
            } else {
                start = lmid + 1;
            }
        }

        return -1;
    }
};


//  1 3 5 7 9
//  2 4 6 8

