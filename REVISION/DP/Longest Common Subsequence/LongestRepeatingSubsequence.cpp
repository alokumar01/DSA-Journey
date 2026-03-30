#include <iostream>
using namespace std;
#include <string>
#include <vector>

/*
===========================================================
🧠 PROBLEM:
Longest Repeating Subsequence (LRS)
===========================================================

💡 CORE IDEA:
Find the longest subsequence that appears **at least twice**
in the same string.

👉 BUT:
The same index cannot be reused.

-----------------------------------------------------------
🔁 PATTERN (VERY IMPORTANT):

LRS = LCS(s, s) with condition (i != j)

-----------------------------------------------------------
🚨 HOW TO RECOGNIZE QUICKLY:

If question says:
✔ "repeating subsequence"
✔ "same string"
✔ "subsequence (not substring)"

👉 Immediately think:
   LCS with itself + (i != j)

-----------------------------------------------------------
🛠 APPROACH:

1. Take string s
2. Compare it with itself → LCS(s, s)
3. Modify condition:
      if (s1[i-1] == s2[j-1] && i != j)
4. Return dp[n][n]

-----------------------------------------------------------
⚠️ IMPORTANT LOGIC:

Why (i != j)?

👉 To avoid matching same character with itself

Example:
A (index 1) ❌ A (index 1) → NOT allowed
A (index 1) ✅ A (index 2) → allowed

-----------------------------------------------------------
⏱ COMPLEXITY:

Time Complexity  : O(n^2)
Space Complexity : O(n^2)

-----------------------------------------------------------
🧠 MEMORY TRICK:

"Repeating → Same string → Avoid same index → i != j"

===========================================================
*/

// Function to compute LRS using LCS logic
int lrs(string &s1) {
    int n = s1.size();

    // DP table
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            // Key condition: match + different index
            if (s1[i - 1] == s1[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][n];
}

int main() {
    string s = "AABEBCDD";

    int ans = lrs(s);

    cout << "Length of Longest Repeating Subsequence: " << ans;

    return 0;
}