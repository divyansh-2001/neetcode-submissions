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
    void traverse(TreeNode* root, int depth, int pos, unordered_map<int, pair<int,int>>& m, int& depthMax){
        if(!root){
            return;
        }

        if(m.find(depth) == m.end() || m[depth].first < pos){
            m[depth] = {pos, root->val};
        }

        depthMax = max(depth, depthMax);

        traverse(root->left, depth+1, pos-1, m, depthMax);
        traverse(root->right, depth+1, pos+1, m, depthMax);

        return;
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        unordered_map<int, pair<int,int>> m;
        vector<int> v;
        int depthMax = -1;

        traverse(root, 0, 0, m, depthMax);

        for(int i=0;i<=depthMax;i++){
            v.push_back(m[i].second);
        }

        return v;
    }
};
