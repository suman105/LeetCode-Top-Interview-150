 class Solution {
    public:
        void inorder(TreeNode *root,vector<int> &v){
            if(!root)   return;
            inorder(root->left,v);
            v.push_back(root->val);
            inorder(root->right,v);
        }
        int getMinimumDifference(TreeNode* root) 
        {
            vector<int> v;
            inorder(root,v);
            int m=INT_MAX;
            for(int i=0;i<v.size()-1;i++)   m = min(m,v[i+1]-v[i]);
            return m;
        }
    };