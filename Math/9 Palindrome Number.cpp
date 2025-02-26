class Solution {
    public:
        bool isPalindrome(int x) 
        {
            long long int temp,a,r,sum=0;
            temp=x,a=x;
            while(a>0)
            {
                r=a%10;
                sum = sum*10 + r;
                a=a/10;
            }
            return sum==temp;
        }
    };