class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) 
        {
            vector<int> result;
            int carry=1;
            for(int i=digits.size()-1;i>=0;--i){
                if((carry+digits[i]) > 9){
                    result.push_back((carry+digits[i])%10);
                    carry=1;
                }
                else{
                    result.push_back(carry+digits[i]);
                    carry=0;
                }
            }
            if(carry)   result.push_back(carry);
            reverse(result.begin(),result.end());
            return result;
        }
    };