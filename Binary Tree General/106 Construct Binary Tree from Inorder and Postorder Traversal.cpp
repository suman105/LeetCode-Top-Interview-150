class Solution {
    public:
        TreeNode* helper(vector<int>& postorder, int &postIndex, vector<int>& inorder, int start, int end){
            if(start > end) return nullptr;
    
            int rootVal = postorder[postIndex--];
            TreeNode *root = new TreeNode(rootVal);
    
            int rootIndex = -1;
            for(int i=start; i<=end; i++){
                if(inorder[i]   == rootVal){
                    rootIndex = i;
                    break;
                }
            }
    
            root->right = helper(postorder, postIndex, inorder, rootIndex+1, end);
            root->left = helper(postorder, postIndex, inorder, start, rootIndex-1);
    
            return root;
        }
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
        {
            int postIndex = postorder.size()-1;
            return helper(postorder, postIndex, inorder, 0, inorder.size()-1);    
        }
    };