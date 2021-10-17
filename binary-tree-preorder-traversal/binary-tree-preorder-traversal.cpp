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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;
        dfs(root,pre);
        return pre;
    }
    
    void dfs(TreeNode*root,vector<int> &pre)
    {
        if(root==NULL)
            return;
        pre.push_back(root->val);
        dfs(root->left,pre);
        dfs(root->right,pre);
    }
};