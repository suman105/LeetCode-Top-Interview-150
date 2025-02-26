#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int n = s.size(), wordLen = words[0].size(), numWords = words.size();
        int totalLen = wordLen * numWords;

        if (n < totalLen) return {}; // Edge case: If s is shorter than the total word length, no solution.

        unordered_map<string, int> wordCount;
        for (string& word : words) wordCount[word]++; // Count occurrences of each word

        // Try starting at every offset within a word length
        for (int start = 0; start < wordLen; start++) {
            int left = start, right = start;
            unordered_map<string, int> windowCount;
            int wordsMatched = 0;

            while (right + wordLen <= n) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordCount.find(word) != wordCount.end()) { // Valid word found
                    windowCount[word]++;
                    if (windowCount[word] == wordCount[word]) wordsMatched++;

                    // If window size exceeds allowed length, remove words from the left
                    while ((right - left) > totalLen) {
                        string leftWord = s.substr(left, wordLen);
                        left += wordLen;
                        if (windowCount[leftWord] == wordCount[leftWord]) wordsMatched--;
                        windowCount[leftWord]--;
                    }

                    if (wordsMatched == wordCount.size()) result.push_back(left);
                } 
                else { // Invalid word, reset window
                    windowCount.clear();
                    wordsMatched = 0;
                    left = right;
                }
            }
        }
        return result;
    }
};
