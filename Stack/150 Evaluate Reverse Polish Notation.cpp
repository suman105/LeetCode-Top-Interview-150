class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int> st;
            
            for (string &token : tokens) {
                if (token == "+" || token == "-" || token == "*" || token == "/") {
                    int b = st.top(); st.pop();  // Second operand
                    int a = st.top(); st.pop();  // First operand
                    
                    if (token == "+") st.push(a + b);
                    else if (token == "-") st.push(a - b);
                    else if (token == "*") st.push(a * b);
                    else if (token == "/") st.push(a / b);  // Truncates toward zero
                } 
                else {
                    st.push(stoi(token));  // Convert string to integer
                }
            }
            
            return st.top();  // Final result
        }
    };
    