class Solution {
    public:
        int sum=0;
        void helper(TreeNode* root, int t)
        {
            if(!root)  return;
            t = t*10+root->val;
            if(!root->left && !root->right){
                sum += t;
                return;
            }
            helper(root->left,t);
            t /= 10;
            t = t*10+root->val;
            helper(root->right,t);
        }
        int sumNumbers(TreeNode* root) 
        {
            helper(root,0);
            return sum;    
        }
    };