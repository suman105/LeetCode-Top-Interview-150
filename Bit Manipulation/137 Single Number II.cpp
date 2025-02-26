#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;

        for (int num : nums) {
            ones = (ones ^ num) & ~twos;  // Add to "ones" unless it's in "twos"
            twos = (twos ^ num) & ~ones;  // Add to "twos" unless it's in "ones"
        }

        return ones;  // The unique element is stored in "ones"
    }
};
