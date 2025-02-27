class Solution {
public:
    int totalNQueens(int n) {
        return solve(0, n, 0, 0, 0);
    }
    
private:
    int solve(int row, int n, int cols, int diags1, int diags2) {
        if (row == n) return 1; // All queens placed successfully

        int availablePositions = ((1 << n) - 1) & ~(cols | diags1 | diags2); // All valid positions for the current row
        int count = 0;

        while (availablePositions) {
            int position = availablePositions & -availablePositions; // Extract lowest set bit (first available position)
            availablePositions ^= position; // Remove this position from availablePositions
            
            count += solve(row + 1, n, cols | position, (diags1 | position) << 1, (diags2 | position) >> 1);
        }

        return count;
    }
};
