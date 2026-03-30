#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
===========================================================
🧠 PROBLEM:
Minimum number of deletions to make a string palindrome
===========================================================

💡 CORE IDEA:
Instead of deleting directly,
→ Find the longest part which is already palindrome

👉 That is: Longest Palindromic Subsequence (LPS)
-----------------------------------------------------------
🔁 PATTERN (VERY IMPORTANT):

LPS = LCS(s, reverse(s))

So,
Minimum deletions = n - LPS
                  = n - LCS(s, reverse(s))

-----------------------------------------------------------
🚨 HOW TO RECOGNIZE QUICKLY:

If question says:
✔ "make string palindrome"
✔ "minimum deletions"
✔ "subsequence allowed"

👉 Immediately think:
   LPS → LCS with reverse string

-----------------------------------------------------------
🛠 APPROACH:

1. Take original string s
2. Reverse it → rev
3. Find LCS(s, rev)
4. Answer = n - LCS

-----------------------------------------------------------
⏱ COMPLEXITY:

Time Complexity  : O(n^2)
Space Complexity : O(n^2)

(Optimization possible to O(n) space)

-----------------------------------------------------------
🧠 MEMORY TRICK:

"Delete minimum → Keep maximum palindrome → LPS → LCS(reverse)"

===========================================================
*/

// Function to compute LCS
int lcs(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();

    // DP table where dp[i][j] = LCS of s1[0..i-1] & s2[0..j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // If characters match → take diagonal +1
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                // Else take max of left and top
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}

int main() {
    string s = "agbcba";

    // Step 1: Reverse string
    string rev = s;
    reverse(rev.begin(), rev.end());

    // Step 2: Find LCS → gives LPS
    int lps = lcs(s, rev);

    // Step 3: Apply formula
    int minDeletions = s.size() - lps;

    cout << "Minimum deletions: " << minDeletions;

    return 0;
}