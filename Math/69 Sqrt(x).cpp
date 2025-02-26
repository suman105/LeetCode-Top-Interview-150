class Solution {
    public:
        int mySqrt(int x) 
        {
            int res=0,l=0,r=x;
            while(l<=r) 
            {
                long long int m = l+(r-l)/2;
                if(m*m==x)  return m;
                else if(m*m < x){
                    l=m+1;
                    res=m;
                }
                else    r=m-1;
            }   
            return res;
        }
    };