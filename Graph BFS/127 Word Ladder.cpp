class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set<string> words(wordList.begin(), wordList.end());
            if (!words.count(endWord)) return 0; // `endWord` must be in `wordList`
            
            queue<pair<string, int>> q; // {word, transformation steps}
            q.push({beginWord, 1});
            
            while (!q.empty()) {
                auto [word, steps] = q.front();
                q.pop();
                
                if (word == endWord) return steps; // Found shortest path
                
                for (int i = 0; i < word.size(); i++) { // Try changing each letter
                    char original = word[i];
    
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue; // Skip same letter
                        
                        word[i] = c; // Mutate
                        
                        if (words.count(word)) { // If valid word, push to queue
                            words.erase(word); // Mark as visited
                            q.push({word, steps + 1});
                        }
                    }
    
                    word[i] = original; // Restore original character
                }
            }
            
            return 0; // If `endWord` is unreachable
        }
    };