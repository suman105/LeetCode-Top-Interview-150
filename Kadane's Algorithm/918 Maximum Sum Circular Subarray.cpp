class Solution {
    public:
        int maxSubarraySumCircular(vector<int>& nums) 
        {
            int maxSum = INT_MIN, minSum = INT_MAX;
            int currentMax = 0, currentMin = 0;
            int total = 0;
    
            for(int &num : nums)
            {
                currentMax = max(num, currentMax + num);
                maxSum = max(maxSum, currentMax);
    
                currentMin = min(num, currentMin + num);
                minSum = min(currentMin, minSum);
    
                total += num;
            }
    
            if(maxSum < 0)  return maxSum;
    
            return max(maxSum, total - minSum);
        }
    };