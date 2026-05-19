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
    bool getPath(TreeNode* root, TreeNode* p, vector<TreeNode*>& v){
        if(!root){
            return false;
        }

        v.push_back(root);

        if(root == p){
            return true;
        }

        bool a = getPath(root->left, p, v);
        bool b = getPath(root->right, p, v);

        if(!a && !b){
            v.pop_back();
            return false;
        }

        return true;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1;
        vector<TreeNode*> v2;
        getPath(root, p, v1);
        getPath(root, q, v2);

        int i = 0, j = 0;
        TreeNode* ans = NULL;

        while(i < v1.size() && j < v2.size()){
            if(v1[i] == v2[j]){
                ans = v1[i];
            } else {
                break;
            }

            i++;
            j++;
        }

        return ans;
    }
};
