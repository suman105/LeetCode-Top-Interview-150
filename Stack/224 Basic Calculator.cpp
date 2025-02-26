class Solution {
    public:
        int calculate(string s) {
            stack<int> stack;   
            int currentResult = 0;  // Current result
            int sign = 1;           // 1 for '+', -1 for '-'
            int n = s.size();
            
            for (int i = 0; i < n; ++i) {
                char ch = s[i];
                
                if (isdigit(ch)) {
                    int num = 0;
                    // Build the current number (it may have multiple digits)
                    while (i < n && isdigit(s[i])) {
                        num = num * 10 + (s[i] - '0');
                        ++i;
                    }
                    // After building the number, apply the current sign
                    currentResult += sign * num;
                    --i;  // We moved one step extra, so adjust the index
                } else if (ch == '+') {
                    sign = 1;  // Positive sign
                } else if (ch == '-') {
                    sign = -1;  // Negative sign
                } else if (ch == '(') {
                    // Push the current result and sign onto the stack
                    stack.push(currentResult);
                    stack.push(sign);
                    // Reset the current result and sign for the new expression inside parentheses
                    currentResult = 0;
                    sign = 1;
                } else if (ch == ')') {
                    // Pop the sign and previous result
                    currentResult *= stack.top(); stack.pop();  // Apply the sign
                    currentResult += stack.top(); stack.pop();  // Add the previous result
                }
            }
            
            return currentResult;
        }
    };