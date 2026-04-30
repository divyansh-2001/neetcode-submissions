class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int total = m*n;
        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        vector<int> ans;

        while( total > 0 ){
            for(int i=left;i<=right && total > 0;i++){
                ans.push_back(matrix[top][i]);
                total--;
            }

            top++;

            if(total <= 0){
                break;
            }

            for(int i=top;i<=bottom && total > 0;i++){
                ans.push_back(matrix[i][right]);
                total--;
            }

            right--;

            if(total <= 0){
                break;
            }

            for(int i=right;i>=left && total > 0;i--){
                ans.push_back(matrix[bottom][i]);
                total--;
            }

            bottom--;

            if(total <= 0){
                break;
            }

            for(int i=bottom;i>=top && total > 0;i--){
                ans.push_back(matrix[i][left]);
                total--;
            }

            left++;
        }

        return ans;

    }
};
