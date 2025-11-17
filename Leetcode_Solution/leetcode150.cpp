class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string token : tokens) {
            if (token == "+" || token == "-" || token == "/" || token == "*") {
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();

                int res;
                if (token == "+") 
                    res = first + second;
                else if (token == "-") 
                    res = first - second;
                else if (token == "*") 
                    res = first * second;
                else
                    res = first / second;

                s.push(res);
            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};


// Evaluate Reverse Polish Notation — Notes
// Logic

// Use a stack to evaluate postfix expression.
// For each token:
// If it’s a number → push to stack.
// If it’s an operator →
// Pop second, then first
// Compute first op second
// Push result back.
// Final answer is the top of the stack.


// 🕒 Time Complexity (TC)
// O(n)
// Each token is processed once.
// 💾 Space Complexity (SC)
// O(n)

// In worst case (all numbers), stack stores all tokens.