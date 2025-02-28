class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        // Lambda function for DFS traversal
        auto dfs = [&](int i, int j, auto&& dfs_ref) -> void {
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') 
                return;
            
            board[i][j] = 'T'; // Mark as safe
            dfs_ref(i + 1, j, dfs_ref);
            dfs_ref(i - 1, j, dfs_ref);
            dfs_ref(i, j + 1, dfs_ref);
            dfs_ref(i, j - 1, dfs_ref);
        };

        // Step 1: Mark all border 'O's and their connected 'O's as 'T'
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(i, 0, dfs);
            if (board[i][n - 1] == 'O') dfs(i, n - 1, dfs);
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(0, j, dfs);
            if (board[m - 1][j] == 'O') dfs(m - 1, j, dfs);
        }

        // Step 2: Convert all remaining 'O's to 'X' and restore 'T' back to 'O'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X'; // Surrounded region
                else if (board[i][j] == 'T') board[i][j] = 'O'; // Restore safe region
            }
        }
    }
};
