class Solution {
    public:
        bool isSubsequence(string s, string t) 
        {
            int i=0,j=0;
            while(j<t.size())
            {
                if(s[i]==t[j])  ++i;
                ++j;
            }    
            if(s.size()==i) return 1;
            return 0;
        }
    };