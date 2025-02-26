class Solution {
    public:
        TreeNode* invertTree(TreeNode* root) {
            return invert(root);
        }
    
        TreeNode* invert(TreeNode* root){
            if(!root)   return NULL;
            TreeNode* leftNode = invert(root->left);
            TreeNode* rightNode = invert(root->right);
            root->right = leftNode;
            root->left = rightNode;
            return root;
        }
    };