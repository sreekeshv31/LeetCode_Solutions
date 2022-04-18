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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return preOrderTraverse(s, t);
    }

private:
    bool preOrderTraverse(TreeNode *s, TreeNode *t) {
        return s && (isSame(s, t) ||
                     preOrderTraverse(s->left, t) ||
                     preOrderTraverse(s->right, t));
    }

    bool isSame(TreeNode *x,TreeNode *y) {
        if (!x && !y) {
            return true;
        }
        if (!x || !y) {
            return false;
        }
        return x->val == y->val &&
               isSame(x->left, y->left) &&
               isSame(x->right, y->right);
    }
};