class Solution {
    public:
        int snakesAndLadders(vector<vector<int>>& board) {
            int n = board.size();
            vector<int> flattened(n * n + 1, -1); // Convert board to 1D
            
            bool leftToRight = true;
            int idx = 1;
    
            for (int row = n - 1; row >= 0; row--) { // Start from bottom row
                if (leftToRight) {
                    for (int col = 0; col < n; col++) 
                        flattened[idx++] = board[row][col];
                } else {
                    for (int col = n - 1; col >= 0; col--) 
                        flattened[idx++] = board[row][col];
                }
                leftToRight = !leftToRight;
            }
    
            // BFS Initialization
            queue<pair<int, int>> q; // {position, moves}
            vector<bool> visited(n * n + 1, false);
            q.push({1, 0});
            visited[1] = true;
    
            while (!q.empty()) {
                auto [pos, moves] = q.front();
                q.pop();
    
                if (pos == n * n) return moves; // Reached the end
                
                for (int dice = 1; dice <= 6; dice++) {
                    int nextPos = pos + dice;
                    if (nextPos > n * n) break;
    
                    if (flattened[nextPos] != -1) 
                        nextPos = flattened[nextPos]; // Move if ladder/snake
    
                    if (!visited[nextPos]) {
                        visited[nextPos] = true;
                        q.push({nextPos, moves + 1});
                    }
                }
            }
    
            return -1; // If unreachable
        }
    };