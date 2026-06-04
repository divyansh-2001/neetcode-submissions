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
    bool helper(TreeNode* root, TreeNode* subRoot, TreeNode* subRootRoot){
        if(!root && !subRoot){
            return true;
        }

        if(!root || !subRoot){
            return false;
        }

        bool a = false;

        if(root->val == subRoot->val){
            a = helper(root->left, subRoot->left, subRootRoot) && helper(root->right, subRoot->right, subRootRoot);
            if(a){
                return a;
            }
        }

        return helper(root->left, subRootRoot, subRootRoot) || helper(root->right, subRootRoot, subRootRoot);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return helper(root, subRoot, subRoot);
    }
};
