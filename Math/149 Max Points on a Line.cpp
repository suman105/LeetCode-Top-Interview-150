class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 1) return points.size();
        
        int maxPointsOnLine = 1;
        
        for (int i = 0; i < points.size(); i++) {
            unordered_map<string, int> slopeMap;
            int samePoint = 0, localMax = 0;
            
            for (int j = i + 1; j < points.size(); j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                // Handle duplicate points
                if (dx == 0 && dy == 0) {
                    samePoint++;
                    continue;
                }

                // Reduce the fraction (dy/dx) using GCD
                int gcdValue = gcd(dx, dy);
                dx /= gcdValue;
                dy /= gcdValue;

                // Store slope as a string key
                string slope = to_string(dy) + "/" + to_string(dx);
                slopeMap[slope]++;
                localMax = max(localMax, slopeMap[slope]);
            }
            
            maxPointsOnLine = max(maxPointsOnLine, localMax + samePoint + 1);
        }
        
        return maxPointsOnLine;
    }

private:
    // Function to compute GCD
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
