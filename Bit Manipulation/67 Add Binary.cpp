class Solution {
    public:
        string addBinary(string a, string b) {
        if (a == "0" && b == "0") return "0";
        int carry = 0;
        string result = "";
    
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry > 0) {
            int num1 = (i >= 0) ? a[i--] - '0' : 0;
            int num2 = (j >= 0) ? b[j--] - '0' : 0;
    
            int sum = num1 ^ num2 ^ carry;
            carry = (num1 & num2) | (num1 & carry) | (num2 & carry);
    
            result = to_string(sum) + result;
        }
    
        return result;
    }
    };