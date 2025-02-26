class Solution {
    public:
        string simplifyPath(string path) {
            vector<string> stack;  // To store valid directory names
            stringstream ss(path);
            string token;
            
            // Split the path by '/'
            while (getline(ss, token, '/')) {
                if (token == "" || token == ".") {
                    continue;  // Ignore empty or current directory references
                } else if (token == "..") {
                    if (!stack.empty()) {
                        stack.pop_back();  // Move up one directory
                    }
                } else {
                    stack.push_back(token);  // Add the directory to the stack
                }
            }
            
            // Rebuild the simplified path
            string result = "";
            for (const string& dir : stack) {
                result += "/" + dir;
            }
            
            // If the stack is empty, return the root path "/"
            return result.empty() ? "/" : result;
        }
    };
    