#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

/*
===========================================================
PROBLEM:
Check if string A is a subsequence of string B
===========================================================

 CORE IDEA:
A is a subsequence of B if all characters of A
appear in B in the same order (not necessarily contiguous)

-----------------------------------------------------------
 PATTERN (VERY IMPORTANT):

Subsequence check = LCS(A, B)

If:
   LCS(A, B) == length of A
👉 Then A is a subsequence of B

-----------------------------------------------------------
 HOW TO RECOGNIZE QUICKLY:

If question says:
✔ "is subsequence"
✔ "order must be same"
✔ "skipping allowed"

👉 Think:
   LCS OR Two-pointer approach

-----------------------------------------------------------
🛠 APPROACH 1: (DP - LCS)

1. Compute LCS(A, B)
2. If LCS == length of A → TRUE
3. Else → FALSE

-----------------------------------------------------------
🛠 APPROACH 2: (Optimal - Two Pointers)

1. Use two pointers i (for A), j (for B)
2. If characters match → move both
3. Else → move only j
4. If i reaches end → subsequence exists

-----------------------------------------------------------
⏱ COMPLEXITY:

LCS Approach:
Time  : O(n * m)
Space : O(n * m)

Two Pointer Approach:
Time  : O(n + m)
Space : O(1)

-----------------------------------------------------------
 MEMORY TRICK:

"Subsequence → Order matters → Skip allowed → 2 pointers"

===========================================================
*/

// LCS function (DP approach)
int lcs(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}

// Optimal approach (Two pointers)
bool isSubsequence(string a, string b) {
    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j])
            i++;
        j++;
    }

    return i == a.size();
}

int main() {
    string a = "AXY";
    string b = "ADXCPY";

    // 🔸 Approach 1: LCS
    int ans = lcs(a, b);

    if (ans == a.length())
        cout << "LCS Method: True\n";
    else
        cout << "LCS Method: False\n";

    // 🔸 Approach 2: Two Pointer
    if (isSubsequence(a, b))
        cout << "Two Pointer Method: True\n";
    else
        cout << "Two Pointer Method: False\n";

    return 0;
}