class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push_back(ch);
            } else {
                if (stack.empty())
                    return false;
                char top = stack.back();

                if ((top == '(' && ch == ')') || (top == '{' && ch == '}') ||
                    (top == '[' && ch == ']')) {
                    stack.pop_back();
                } else {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};


////// Short Notes //////

// ⭐ Valid Parentheses – Short Notes
// Approach
// Use a stack to match opening and closing brackets.
// Steps:
// Push opening brackets: ( { [
// On closing bracket:
// if stack empty → invalid
// if top matches → pop
// else → invalid
// Finally, stack must be empty
// ✔ Time: O(n)
// ✔ Space: O(n)


// ⭐ Why use vector<char> as a stack?
// ✔ vector is ideal for stack operations

// Supports push_back, pop_back, back
// Contiguous memory → faster & more cache-friendly
// No extra overhead
// ✔ Cleaner intent than string
// string is meant for text, not stack operations
// Managing characters inside string is less semantically correct
// Extra null-termination/internal logic → slightly slower
// ✔ Faster than std::stack
// std::stack is just a wrapper over deque
// More overhead and worse memory locality
// vector is the most efficient stack-like container for chars
// 📌 Summary (memorize)

// Use vector<char> because it's the fastest, simplest, and most intuitive structure for stack behavior.
// string is for text, and stack has more overhead.