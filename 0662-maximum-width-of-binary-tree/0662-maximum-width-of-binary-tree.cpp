class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long> >q;
        q.push({root, 0});
        long ans =0 ; 

        while(!q.empty()){

            long size = q.size();
            long start = q.front().second;
            long end  = q.back().second;

            ans = max(ans , end - start+1);

            for(long i =0 ; i<size;i++){
            pair<TreeNode*,int> p = q.front();
            TreeNode* front = p.first;
            long idx = p.second;
            q.pop();

            if(front->left){q.push({front->left, 2*idx+1});}
            if(front->right){q.push({front->right , 2*idx+2});}

            }
           
        }
        return ans;
    }
};