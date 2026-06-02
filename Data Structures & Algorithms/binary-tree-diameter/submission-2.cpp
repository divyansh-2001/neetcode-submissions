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
    int getAns(TreeNode* root, int& ans){
        if(!root){
            return 0;
        }

        int leftMaxHeight = getAns(root->left, ans);
        int rightMaxHeight = getAns(root->right, ans);

        ans = max(ans, max(max(leftMaxHeight + rightMaxHeight + 1, leftMaxHeight+1), rightMaxHeight+1));
        return 1+max(leftMaxHeight, rightMaxHeight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }

        int ans = 1;
        getAns(root, ans);

        return ans;
    }
};
