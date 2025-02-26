class Solution {
    public:
        vector<string> summaryRanges(vector<int>& nums) 
        {
            int left=0, right=0, n=nums.size();
            vector<string> result;
    
            if(!n)  return result;
            
            for(int i=1; i<n; i++)
            {
                if(nums[i] == nums[i-1]+1)  right = i;
                else{
                    if(left == right)   result.push_back(to_string(nums[left]));
                    else    result.push_back(to_string(nums[left])+"->"+to_string(nums[right]));
                    left = right = i;
                }
            }
    
            if(left == right)   result.push_back(to_string(nums[left]));
            else    result.push_back(to_string(nums[left])+"->"+to_string(nums[right]));
    
            return result;    
        }
    };