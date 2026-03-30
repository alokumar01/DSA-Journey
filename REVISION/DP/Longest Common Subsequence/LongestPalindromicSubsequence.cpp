#include <bits/stdc++.h>
using namespace std;

/*
============================================================
🧠 PROBLEM: Longest Palindromic Subsequence (LPS)
============================================================

📌 Definition:
Given a string s, find the length of the longest subsequence
which is a palindrome.

👉 Subsequence = not necessarily contiguous

------------------------------------------------------------
💡 KEY IDEA (PATTERN):

LPS(s) = LCS(s, reverse(s))

So we convert the problem into:
👉 Longest Common Subsequence (LCS)

------------------------------------------------------------
🧩 STEPS:

1. Take string s
2. Reverse it → rev
3. Apply LCS(s, rev)
4. Return dp[n][n]

------------------------------------------------------------
📊 DP DEFINITION:

dp[i][j] = LCS length of:
           s[0...i-1] and rev[0...j-1]

------------------------------------------------------------
🔁 TRANSITION:

if (s[i-1] == rev[j-1])
    dp[i][j] = 1 + dp[i-1][j-1]
else
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

------------------------------------------------------------
⚙️ BASE CASE:

dp[i][0] = 0
dp[0][j] = 0

------------------------------------------------------------
📈 COMPLEXITY:

Time Complexity  : O(n^2)
Space Complexity : O(n^2)

------------------------------------------------------------
🔥 RELATED PROBLEMS:

1. Minimum Insertions = n - LPS
2. Minimum Deletions = n - LPS

============================================================
*/

int lps(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());

    int n = s.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // characters match
            if (s[i - 1] == rev[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            // characters do not match
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][n];
}

int main() {

    string s = "abgcba";

    int ans = lps(s);

    cout << "LPS length = " << ans << endl;

    return 0;
}