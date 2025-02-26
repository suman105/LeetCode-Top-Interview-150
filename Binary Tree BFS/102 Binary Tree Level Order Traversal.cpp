class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) 
        {
            vector<vector<int>> result;
            vector<int> v;
            if(!root)   return result;
            queue<struct TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                struct TreeNode *temp = NULL;
                int g=q.size();
                for(int i=0;i<g;i++){
                    temp = q.front();
                    v.push_back(temp->val);
                    q.pop();
                    if(temp->left)  q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
                result.push_back(v);
                v.clear();
            }
    
            return result;
        }
    };