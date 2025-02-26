class Solution {
    public:
        bool helper(TreeNode *root,int sum, int t)
        {
            if(!root)   return false;
            if(!root->left && !root->right){
                if(t==(sum+root->val))  return true;
                return false;
            }
            
            bool left = helper(root->left,sum+root->val,t);
            bool right = helper(root->right,sum+root->val,t);
            return left||right;
        }
    
        bool hasPathSum(TreeNode* root, int t) 
        {
            int sum=0;
            if(!root)   return false;
            return helper(root,sum,t);
        }
    };