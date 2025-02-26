class Solution {
    public:
        void gameOfLife(vector<vector<int>>& board) {
            int rows = board.size();
            if (rows == 0) return;
            int cols = board[0].size();
    
            // Directions for 8 neighbors
            int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                                    {0, -1},          {0, 1},
                                    {1, -1},  {1, 0}, {1, 1}};
    
            // Iterate through each cell
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    int liveNeighbors = 0;
    
                    // Count live neighbors
                    for (const auto& dir : directions) {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if (x >= 0 && x < rows && y >= 0 && y < cols && abs(board[x][y]) == 1) {
                            liveNeighbors++;
                        }
                    }
    
                    // Apply rules
                    if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                        board[i][j] = -1; // Cell dies
                    } else if (board[i][j] == 0 && liveNeighbors == 3) {
                        board[i][j] = 2; // Cell becomes alive
                    }
                }
            }
    
            // Update the board to the next state
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    if (board[i][j] == -1) {
                        board[i][j] = 0;
                    } else if (board[i][j] == 2) {
                        board[i][j] = 1;
                    }
                }
            }
        }
    };