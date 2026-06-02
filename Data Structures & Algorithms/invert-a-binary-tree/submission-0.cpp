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
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return root;
        }
        
        TreeNode* ans = new TreeNode(root->val);
        TreeNode* ansLeft = invertTree(root->left);
        TreeNode* ansRight = invertTree(root->right);

        ans -> left = ansRight;
        ans -> right = ansLeft;

        return ans;
    }
};
