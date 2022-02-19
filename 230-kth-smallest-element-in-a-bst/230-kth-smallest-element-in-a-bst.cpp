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
    int kthSmallest(TreeNode* root, int k) {
        int fid;
        inorder(root,fid,k);
        return fid;
        
    }
    void inorder(TreeNode *root,int &fid,int &k)
    {
     if(root==NULL)
         return;
     inorder(root->left,fid,k);
    if(!k)
        return;
    fid = root->val;
    inorder(root->right,fid,--k);
    }
    
};