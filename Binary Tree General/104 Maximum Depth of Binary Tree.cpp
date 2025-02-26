class Solution {
    public:
        int maxDepth(TreeNode* root) 
        {
            if(!root)   return 0;
            int leftTreeHeight = maxDepth(root->left);
            int rightTreeHeight = maxDepth(root->right);
            return 1+max(leftTreeHeight, rightTreeHeight);
        }
    };