class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size() - 1, grid[0].size() - 1);
    }

private:
    Node* build(vector<vector<int>>& grid, int rowStart, int colStart, int rowEnd, int colEnd) {
        // Check if the current region is uniform
        if (isUniform(grid, rowStart, colStart, rowEnd, colEnd)) {
            return new Node(grid[rowStart][colStart], true);
        }

        int midRow = (rowStart + rowEnd) / 2;
        int midCol = (colStart + colEnd) / 2;

        // Recursively construct the four quadrants
        Node* topLeft = build(grid, rowStart, colStart, midRow, midCol);
        Node* topRight = build(grid, rowStart, midCol + 1, midRow, colEnd);
        Node* bottomLeft = build(grid, midRow + 1, colStart, rowEnd, midCol);
        Node* bottomRight = build(grid, midRow + 1, midCol + 1, rowEnd, colEnd);

        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    // Helper function to check if a region is uniform (all 0s or all 1s)
    bool isUniform(vector<vector<int>>& grid, int rowStart, int colStart, int rowEnd, int colEnd) {
        int val = grid[rowStart][colStart];
        for (int i = rowStart; i <= rowEnd; i++) {
            for (int j = colStart; j <= colEnd; j++) {
                if (grid[i][j] != val) return false;
            }
        }
        return true;
    }
};
