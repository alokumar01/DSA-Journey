#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
===========================================================
🧠 PROBLEM:
Minimum Insertions to Make String Palindrome
===========================================================

💡 CORE IDEA:

👉 We don’t directly insert characters
👉 Instead, we find:

   Longest Palindromic Subsequence (LPS)

-----------------------------------------------------------
🔁 PATTERN (VERY IMPORTANT):

LPS = LCS(s, reverse(s))

👉 So problem becomes:

Minimum Insertions = n - LPS

-----------------------------------------------------------
🧠 INTUITION:

✔ LPS = longest part already palindrome
✔ Remaining characters → need insertion

-----------------------------------------------------------
🛠 APPROACH:

1. Take string s
2. Reverse it → rev
3. Compute LCS(s, rev)
4. Answer = n - LCS

-----------------------------------------------------------
🔍 WHY LCS WORKS?

👉 Reverse string aligns characters
👉 Common subsequence = palindrome pattern

-----------------------------------------------------------
📌 EXAMPLE:

s   = "AEBCBDA"
rev = "ADBCBEA"

LCS = "ABCBA" (length = 5)

Minimum insertions = 7 - 5 = 2

-----------------------------------------------------------
⏱ COMPLEXITY:

Time  : O(n^2)
Space : O(n^2)

-----------------------------------------------------------
🚨 INTERVIEW POINTS:

✔ This is SUBSEQUENCE problem (not substring)
✔ Classic LCS variation
✔ Very frequently asked

-----------------------------------------------------------
🧠 MEMORY TRICK:

"Keep longest palindrome → insert rest"

Answer = n - LPS

===========================================================
*/


// 🔹 Function to compute LCS
int LCS(string &s1, string &s2) {

    int n = s1.size();
    int m = s2.size();

    // dp[i][j] = LCS length for s1[0...i-1], s2[0...j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            // If characters match
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            // Else take max of excluding either char
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}


// 🔹 Main function to calculate minimum insertions
int minInsertions(string s) {

    // Step 1: Reverse string
    string rev = s;
    reverse(rev.begin(), rev.end());

    // Step 2: Find LPS using LCS
    int lps = LCS(s, rev);

    // Step 3: Compute result
    return s.size() - lps;
}


int main() {

    string s = "AEBCBDA";

    cout << "Minimum Insertions: " << minInsertions(s);

    return 0;
}