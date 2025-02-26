class Solution {
    public:
        int maxProfit(vector<int>& prices) 
        {
            int maxProfit=0, n=prices.size();
    
            for(int i=1; i<n; i++)  
                if(prices[i] > prices[i-1]) maxProfit += prices[i] - prices[i-1];
    
            return maxProfit;    
        }
    };