class Solution {
    public:
        int helper(TreeNode *root,int &m)
        {
            if(!root)   return 0;
            int l=max(0,helper(root->left,m));
            int r=max(0,helper(root->right,m));
            m=max(m,l+r+root->val);
            return root->val+max(l,r);
        }
        int maxPathSum(TreeNode* root) {
            int m=INT_MIN;
            helper(root,m);
            return m;
        }
    };