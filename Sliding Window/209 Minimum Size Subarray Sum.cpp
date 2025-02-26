class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) 
        {
            int n=nums.size();
            int start=0, end=0;
            int currentSum=0, minLength = INT_MAX;
    
            while(end < n)
            {
                currentSum += nums[end++];
    
                while(currentSum >= target){
                    minLength = min(minLength, end-start);
                    currentSum -= nums[start++];
                }
            }   
    
            return minLength == INT_MAX ? 0 : minLength; 
        }
    };