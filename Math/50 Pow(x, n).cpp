class Solution {
    public:
        double myPow(double x, int n) 
        {
            double result=1, y=x;
            if(n<0) y=1/x;
            while(n!=0)
            {
                if(n%2) result=result*y;
                y=y*y;
                n=n/2;
            }  
            while(n!=0)
            {
                if(n%2) result=result*y;
                y=y*y;
                n=n/2;
            } 
            return result; 
        }
    };