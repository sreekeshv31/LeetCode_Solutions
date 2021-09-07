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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)
            return vector<int>();
        vector<int> ans;
        TreeNode *prev = NULL;
        TreeNode *curr = root;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                prev = curr->left;
                while(prev->right!=NULL && prev->right!=curr)
                    prev = prev->right;
                if(prev->right==NULL)
                {
                    prev->right = curr;
                    curr=curr->left;
                }
                else
                {
                    prev->right = NULL;
                    ans.push_back(curr->val);
                    curr= curr->right;
                }
            }
        }
        return ans;
        
    }
};