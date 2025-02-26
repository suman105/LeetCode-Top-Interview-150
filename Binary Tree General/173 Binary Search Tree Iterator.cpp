
 class BSTIterator {
    public:
        stack<TreeNode*> st;
        void push(TreeNode* root){
            while(root){
                st.push(root);
                root = root->left;
            }
        }
    
        BSTIterator(TreeNode* root) {
            push(root);
        }
        
        int next() {
            TreeNode *temp=st.top();
            st.pop();
            push(temp->right);
            return temp->val;
        }
        
        bool hasNext() {
            return !st.empty();
        }
    };
   