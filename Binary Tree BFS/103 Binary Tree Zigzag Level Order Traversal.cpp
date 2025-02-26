 class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
        {
            vector<vector<int>> result;
            vector<int> v;
            int k=0;
            if(!root)   return result;
            queue<struct TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                int g=q.size();
                struct TreeNode *temp=NULL;
                if(k%2==0){
                    for(int i=0;i<g;i++){
                        temp = q.front();
                        v.push_back(temp->val);
                        q.pop();
                        if(temp->left)  q.push(temp->left);
                        if(temp->right) q.push(temp->right);
                    }
                }
                else{
                    stack<int> st;
                    for(int i=0;i<g;i++){
                        temp = q.front();
                        st.push(temp->val);
                        q.pop();
                        if(temp->left)  q.push(temp->left);
                        if(temp->right) q.push(temp->right);
                    }
                    while(!st.empty()){
                        int t=st.top();
                        st.pop();
                        v.push_back(t);
                    }
                    
                }
                result.push_back(v);
                v.clear();
                ++k;
            }
            return result;    
        }
    };