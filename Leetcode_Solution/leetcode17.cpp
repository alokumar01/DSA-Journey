class Solution {
public:
    map<char, string> mp = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    vector<string> res;

    void backtrack(string curr, string &digits, int idx) {
        if (idx == digits.size()) {
            res.push_back(curr);
        } else {
            char crntDigit = digits[idx];
            string mapp = mp[crntDigit];

            for(int i=0; i<mapp.size(); i++) {
                backtrack(curr + mapp[i], digits, idx + 1);
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() != 0) {
            backtrack("", digits, 0);
        }
        return res;
    }
};  