class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxSide = 0;
        
        // Iterate through each cell in the matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        // If we are at the first row or column, we can't form a square larger than 1
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        
        // The area of the largest square is the side length squared
        return maxSide * maxSide;
    }
};
