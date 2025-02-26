class Solution {
    public:
        void helper(TreeNode *root, vector<int> &result,int level,int &max_level){
            if(!root)   return;
            if(max_level < level){
                result.push_back(root->val);
                max_level = level;
            }
            helper(root->right,result,level+1,max_level);
            helper(root->left,result,level+1,max_level);
        }
        vector<int> rightSideView(TreeNode* root)
        {
            int max_level=0;
            vector<int> result;
            helper(root,result,1,max_level);
            return result;
            // vector<int> result;
            // queue<struct TreeNode*> q;
            // q.push(root);
    
            // while(!q.empty())
            // {
            //     int t=q.size();
            //     struct TreeNode *temp=NULL;
            //     for(int i=0;i<t;i++)
            //     {
            //         temp = q.front();
            //         q.pop();
            //         if(root->left)  q.push(root->left);
            //         if(root->right) q.push(root->right);
            //     }
            //     result.push_back(temp->val);
            // }
            // return result;
        }
    };