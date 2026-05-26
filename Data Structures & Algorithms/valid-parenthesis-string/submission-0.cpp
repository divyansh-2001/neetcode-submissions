class Solution {
private:
    bool helper(string s, int idx, int net, vector<vector<int>>& dp){
        if(idx == s.size()){
            if(net != 0){
                return false;
            }

            return true;
        }

        if(net < 0){
            return false;
        }

        if(dp[net][idx] != -1){
            return dp[idx][net];
        }

        bool a = false, b = false, c = false;

        if(s[idx] == '('){
            return dp[idx][net] = helper(s, idx+1, net+1, dp);
        }

        if(s[idx] == ')'){
            return dp[idx][net] = helper(s, idx+1, net-1, dp);
        }

        return dp[idx][net] = helper(s, idx+1, net+1, dp) || helper(s, idx+1, net-1, dp) || helper(s, idx+1, net, dp);
    }
public:
    bool checkValidString(string s) {
        int open = 0;
        int close = 0;

        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        
        return helper(s, 0, 0, dp);
    }
};
