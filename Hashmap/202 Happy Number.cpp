#define MOD 1000000007

class Solution {
public:
    bool isHappy(int n) 
    {
        unordered_set<int> s;
        while(n!=1 && s.find(n)==s.end())
        {
            s.insert(n);
            int prod=0;
            while(n){
                int rem = n%10;
                prod += rem*rem;
                n /= 10;
            }
            n=prod;
        }
        return n==1;
    }
};