class Solution {
public:
    bool isNumber(const std::string& token) {
        if (token.empty()) return false;
        
        size_t start = 0;
        if (token[0] == '-' || token[0] == '+') {
            if (token.length() == 1) return false;
            start = 1;
        }
        
        for (size_t i = start; i < token.length(); ++i) {
            if (!isdigit(token[i])) return false;
        }
        return true;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (const std::string& token : tokens) {
            if (isNumber(token)) {
                st.push(std::stoi(token));
            } 
            else {
                if (st.size() < 2) {
                    std::cerr << "Error: Malformed RPN expression.\n";
                    return 0;
                }

                // Pop elements in strict LIFO order
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();

                int stepResult = 0;
                char op = token[0]; // Extract operator character safely

                switch (op) {
                    case '+': stepResult = num1 + num2; break;
                    case '-': stepResult = num1 - num2; break;
                    case '*': stepResult = num1 * num2; break;
                    case '/': 
                        if (num2 == 0) {
                            std::cerr << "Error: Division by zero!\n";
                            return 0;
                        }
                        stepResult = num1 / num2; 
                        break;
                }
                st.push(stepResult);
            }
        }

        // FIX: Return the final evaluated value from the top of the stack
        if (st.empty()) {
            return 0;
        } else {
            return st.top(); 
        }
    }
};
