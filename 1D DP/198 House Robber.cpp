class Solution {
    public:
        int rob(vector<int>& nums) 
        {
            if(!nums.size())    return 0;
            if(nums.size() == 1)    return nums[0];
    
            int prev1=0, prev2=0;
    
            for(int &num : nums)
            {
                int temp = max(prev1, prev2 + num);
                prev2 = prev1;
                prev1 = temp;
            }
    
            return prev1;    
        }
    };