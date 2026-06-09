/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    int helper(TreeNode* root, int& ans){
        if(!root){
            return 0;
        }
        
        int l = helper(root->left, ans);
        int r = helper(root->right, ans);

        int a = root->val + max(l, 0) + max(r, 0);

        ans = max(ans, max(root->val, a));

        return root->val + max(0, max(l, r));
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;

        helper(root, ans);
        return ans;
    }
};
