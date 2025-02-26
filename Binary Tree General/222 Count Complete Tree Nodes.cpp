class Solution {
    public:
        int countNodes(TreeNode* root) 
        {
            if(!root)   return 0;
            if(!root->left && root->right)  return 0;
            return 1+countNodes(root->left)+countNodes(root->right);
        }
    };