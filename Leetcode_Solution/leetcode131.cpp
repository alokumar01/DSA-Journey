class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;

    bool isPalindrome(string &t) {
        int l = 0, r = t.size() - 1;
        
        while (l < r) {
            if (t[l] != t[r]) {
                return false;
            }
            l++; r--;
        }
        return true;
    }

    void backtrack(string &s, int idx) {
        if (s.length() == idx) {
            ans.push_back(temp);
            return;
        }

        for(int j=idx; j < s.length(); j++) {
            string sub = s.substr(idx, j - idx + 1);

            if (isPalindrome(sub)) {
                temp.push_back(sub); // choose
                backtrack(s, j+1); // recurse
                temp.pop_back(); // undo
            }
        }
    }

    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return ans;
    }
};