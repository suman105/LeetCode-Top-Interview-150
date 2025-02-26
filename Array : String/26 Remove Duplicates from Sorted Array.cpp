class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            set<int> t;
            for(int i=0;i<nums.size();i++)
                t.insert(nums[i]);
            int k=0;
            while(k<t.size()){
                auto it = next(t.begin(), k);
                nums[k] = *it;
                ++k;
            }
            return t.size();
        }
    };