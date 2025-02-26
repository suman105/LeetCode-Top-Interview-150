class Solution {
    public:
        bool wordPattern(string pattern, string s) {
            vector<string> words;
            stringstream ss(s);
            string word;
    
            // Split string `s` into words
            while (ss >> word) {
                words.push_back(word);
            }
    
            // If the number of words doesn't match the pattern length, return false
            if (words.size() != pattern.size()) {
                return false;
            }
    
            unordered_map<char, string> patternToWord;  // Map for pattern -> word
            unordered_map<string, char> wordToPattern;  // Map for word -> pattern
    
            for (int i = 0; i < pattern.size(); i++) {
                char p = pattern[i];
                string w = words[i];
    
                // Check if the character in pattern already maps to a word
                if (patternToWord.find(p) != patternToWord.end()) {
                    if (patternToWord[p] != w) {
                        return false;  // Mismatch
                    }
                } else {
                    patternToWord[p] = w;  // Map pattern character to word
                }
    
                // Check if the word already maps to a character
                if (wordToPattern.find(w) != wordToPattern.end()) {
                    if (wordToPattern[w] != p) {
                        return false;  // Mismatch
                    }
                } else {
                    wordToPattern[w] = p;  // Map word to pattern character
                }
            }
    
            return true;
        }
    };