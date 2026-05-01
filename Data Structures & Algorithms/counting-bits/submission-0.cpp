class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        ans[0] = 0;
        ans[1] = 1;
        ans[2] = 1;
        for(int i=3;i<=n;i++){
            if(i%2){
                ans[i] = ans[i/2] + 1;
            } else {
                ans[i] = ans[i/2];
            }
        }

        return ans;
    }
};
