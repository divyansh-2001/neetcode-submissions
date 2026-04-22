class Solution {
private:
    pair<int,int> getIdxs(int a, int m, int n){
        return {a/n, a%n};
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int start = 0;
        int end = m*n-1;

        while(end >= start){
            int mid = start + (end-start)/2;
            pair<int,int> idxs = getIdxs(mid,m,n);

            if(matrix[idxs.first][idxs.second] == target){
                return true;
            }

            if(matrix[idxs.first][idxs.second] > target){
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return false;
    }
};
