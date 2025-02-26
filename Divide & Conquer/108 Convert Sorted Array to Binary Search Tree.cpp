class Solution {
    public:
        TreeNode* balance(vector<int> &nums, int start, int end)
        {
            if(start > end) return nullptr;
            int mid = start + (end-start)/2;
            TreeNode* node = new TreeNode(nums[mid]);
            node->left = balance(nums,start,mid-1);
            node->right = balance(nums,mid+1,end);
            return node;
        }
    
        TreeNode* sortedArrayToBST(vector<int>& nums) 
        {
            return balance(nums,0,nums.size()-1);    
        }
    };