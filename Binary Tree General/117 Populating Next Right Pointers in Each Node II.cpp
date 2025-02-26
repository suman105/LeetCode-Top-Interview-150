class Solution {
    public:
        Node* connect(Node* root)
        {
            if(!root)   return 0;
            queue<Node*> q;
            q.push(root);
            while(!q.empty())
            {
                Node *temp=NULL;
                int t=q.size();
                for(int i=0;i<t;i++){
                    temp = q.front();
                    q.pop();
                    if(temp->left)  q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                    if(i!=(t-1))    temp->next = q.front();
                }
                temp->next = NULL;
            }
            return root;
        }
    };