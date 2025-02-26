class Solution {
    public:
        string reverseWords(string s) {
            vector<string> words;
            int i = 0, n = s.size();
    
            while (i < n) {
                while (i < n && s[i] == ' ') i++;
                if (i >= n) break;
                int j = i;
                while (j < n && s[j] != ' ') j++;
                words.push_back(s.substr(i, j - i));
                i = j;
            }
    
            string result;
            for (int i = words.size() - 1; i >= 0; i--) {
                result += words[i] + (i > 0 ? " " : "");
            }
    
            return result;
        }
    
    };