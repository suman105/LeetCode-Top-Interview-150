class Solution {
    public:
        vector<double> averageOfLevels(TreeNode* root) 
        {
            vector<double> result;
            double t;
            if(!root)   return result;
    
            queue<struct TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                long long int sum=0;
                struct TreeNode* temp=NULL;
                int g=q.size();
                int k=g;
    
                for(int i=0;i<g;i++){
                    temp = q.front();
                    sum += temp->val;
                    q.pop();
                    if(temp->left)  q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
                t = double(sum)/g;
                result.push_back(t);
            }
            return result;
        }
    };