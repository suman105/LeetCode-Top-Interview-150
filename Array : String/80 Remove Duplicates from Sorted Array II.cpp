class Solution {
    public:
        int removeDuplicates(vector<int>& nums) 
        {
            vector<int> temp;
            map<int,int> m;
            int count=0;
            for(int i=0;i<nums.size();i++)
            {
                if(m.find(nums[i])==m.end())    m[nums[i]]=1;
                else m[nums[i]] += 1;   
            }
            for(auto i : m)
            {
                if(i.second < 2 )   temp.push_back(i.first);
                else{
                    temp.push_back(i.first);
                    temp.push_back(i.first);
                }
    
            }
            int x=0;
            for(auto i : temp)  nums[x++]=i;
            return temp.size();
        }
    };