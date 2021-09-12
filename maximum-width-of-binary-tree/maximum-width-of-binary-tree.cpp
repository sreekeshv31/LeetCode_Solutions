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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int max_size = 0;
        while(!q.empty())
        {
            int size = q.size();
            int start = q.front().second;
            int end = q.back().second;
            max_size = max(max_size,end-start+1);
            for(int i =0;i<size;i++)
            {
                pair<TreeNode*,int> pr = q.front();
                q.pop();
                int idx = pr.second - start;
                if(pr.first->left)
                    q.push({pr.first->left,2*idx+1});
                if(pr.first->right)
                    q.push({pr.first->right,2*idx+2});
            }
        }
        return max_size;
        
    }
};