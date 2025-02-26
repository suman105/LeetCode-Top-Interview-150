#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int index = 0;

        while (index < n) {
            int lineStart = index, lineLength = words[index].size();
            index++;

            // Find the rightmost word that can fit in the line
            while (index < n && lineLength + 1 + words[index].size() <= maxWidth) {
                lineLength += 1 + words[index].size();
                index++;
            }

            int numWords = index - lineStart;
            int numSpaces = maxWidth - (lineLength - (numWords - 1)); // Remaining spaces after words are placed

            string line = words[lineStart];

            // If last line or single word, left justify
            if (index == n || numWords == 1) {
                for (int i = lineStart + 1; i < index; i++) {
                    line += " " + words[i];
                }
                line += string(maxWidth - line.size(), ' '); // Add remaining spaces
            } 
            // Fully justify (distribute spaces evenly)
            else {
                int spaceSlots = numWords - 1;
                int spacePerSlot = numSpaces / spaceSlots;
                int extraSpaces = numSpaces % spaceSlots; // Extra spaces to distribute from left

                for (int i = lineStart + 1; i < index; i++) {
                    int spacesToAdd = spacePerSlot + (extraSpaces-- > 0 ? 1 : 0);
                    line += string(spacesToAdd, ' ') + words[i];
                }
            }

            result.push_back(line);
        }
        return result;
    }
};
