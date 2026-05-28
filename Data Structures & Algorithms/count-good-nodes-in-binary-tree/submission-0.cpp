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
    void dfs(TreeNode* root, int maxEl, int& ans){
        if(!root){
            return;
        }

        if(maxEl <= root->val){
            ans++;
            maxEl = root->val;
        }

        dfs(root->left, maxEl, ans);
        dfs(root->right, maxEl, ans);
        return;
    }
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        if(!root){
            return ans;
        }

        dfs(root, root->val, ans);

        return ans;
    }
};
