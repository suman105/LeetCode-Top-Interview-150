class Solution {
    public:
        int minMutation(string start, string end, vector<string>& bank) {
            unordered_set<string> validGenes(bank.begin(), bank.end());
            if (!validGenes.count(end)) return -1; // `end` must be in `bank`
            
            queue<pair<string, int>> q; // {current_gene, mutation_steps}
            q.push({start, 0});
            
            unordered_set<string> visited; 
            visited.insert(start);
    
            vector<char> mutations = {'A', 'C', 'G', 'T'};
    
            while (!q.empty()) {
                auto [gene, steps] = q.front();
                q.pop();
    
                if (gene == end) return steps; // Found `end`
                
                for (int i = 0; i < 8; i++) { // Try mutating each character
                    char original = gene[i];
    
                    for (char c : mutations) {
                        if (c == original) continue; // Skip same char
                        
                        gene[i] = c; // Mutate
    
                        if (validGenes.count(gene) && !visited.count(gene)) {
                            visited.insert(gene);
                            q.push({gene, steps + 1});
                        }
                    }
    
                    gene[i] = original; // Restore original character
                }
            }
    
            return -1; // If `end` is unreachable
        }
    };