class Solution {
    public:
        vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
            // Step 1: Build the graph
            unordered_map<string, unordered_map<string, double>> graph;
            for (int i = 0; i < equations.size(); ++i) {
                string A = equations[i][0], B = equations[i][1];
                double value = values[i];
                graph[A][B] = value;
                graph[B][A] = 1.0 / value;
            }
            
            // Step 2: Process each query
            vector<double> result;
            for (auto& query : queries) {
                string A = query[0], B = query[1];
                if (graph.find(A) == graph.end() || graph.find(B) == graph.end()) {
                    result.push_back(-1.0);
                } else {
                    unordered_map<string, bool> visited;
                    result.push_back(dfs(A, B, visited, graph));
                }
            }
            
            return result;
        }
        
    private:
        double dfs(const string& A, const string& B, unordered_map<string, bool>& visited, unordered_map<string, unordered_map<string, double>>& graph) {
            if (A == B) return 1.0;
            visited[A] = true;
            
            for (auto& neighbor : graph[A]) {
                if (!visited[neighbor.first]) {
                    double temp = dfs(neighbor.first, B, visited, graph);
                    if (temp != -1.0) {
                        return temp * graph[A][neighbor.first];
                    }
                }
            }
            
            return -1.0;
        }
    };
    