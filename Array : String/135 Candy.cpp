class Solution {
    public:
        int candy(vector<int>& ratings) {
            int n = ratings.size();
            vector<int> candies(n, 1);  // Step 1: Initialize each child with 1 candy
    
            // Step 2: Left-to-right pass
            for (int i = 1; i < n; i++) {
                if (ratings[i] > ratings[i - 1]) {
                    candies[i] = candies[i - 1] + 1;
                }
            }
    
            // Step 3: Right-to-left pass
            for (int i = n - 2; i >= 0; i--) {
                if (ratings[i] > ratings[i + 1]) {
                    candies[i] = max(candies[i], candies[i + 1] + 1);
                }
            }
    
            // Step 4: Return the sum of candies
            return accumulate(candies.begin(), candies.end(), 0);
        }
    };
    