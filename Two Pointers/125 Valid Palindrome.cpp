class Solution {
    public:
        bool isPalindrome(string s) 
        {
            string converted;
            for(char c : s){
                if(isalnum(c))  converted += tolower(c);
            }    
            int i=0,j=converted.size()-1;
            while(i<j){
                if(converted[i] != converted[j])    return false;
                ++i;
                --j;
            }
            return true;
        }
    };