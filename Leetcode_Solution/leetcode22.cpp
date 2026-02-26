class Solution {
public:
    vector<string> ans;
    string res = "";
    void backtrack(int open, int close, int n ) {
        if (open == n && close == n) {
            ans.push_back(res);
            return;
        }

        if (open < n) {
            res.push_back('(');
            backtrack(open + 1, close, n);
            res.pop_back();
        }

        if (close < open) {
            res.push_back(')');
            backtrack(open, close + 1, n);
            res.pop_back();
        }
        
    }

    vector<string> generateParenthesis(int n) {
        backtrack(0, 0, n);
        return ans;    
    }
};