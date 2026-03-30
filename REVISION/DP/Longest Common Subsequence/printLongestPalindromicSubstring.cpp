#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

/*
===========================================================
🧠 PROBLEM:
Longest Palindromic Substring (using DP + reverse trick)
===========================================================

💡 CORE IDEA:
A palindrome reads the same forward and backward

👉 So we try:
   Longest Common Substring (s, reverse(s))

BUT ❗
Not every common substring is a palindrome

-----------------------------------------------------------
🔁 PATTERN (IMPORTANT):

Longest Palindromic Substring
= Longest Common Substring (s, reverse(s))
+ VALIDATION CHECK (index mapping)

-----------------------------------------------------------
🚨 WHY EXTRA CONDITION IS NEEDED?

LCS substring may match characters
but from WRONG positions ❌

👉 So we must ensure:
   substring is actually mirrored in original string

-----------------------------------------------------------
🛠 APPROACH:

1. Take string s
2. Reverse it → rev
3. Apply Longest Common Substring DP
4. Add condition:

      if (i - dp[i][j] == n - j)

   👉 ensures valid palindrome

5. Track max_len and end_idx
6. Return substring

-----------------------------------------------------------
🔍 CONDITION EXPLAINED:

dp[i][j] = length of matching substring

👉 Start index in original string:
   = i - dp[i][j]

👉 Corresponding index from reverse:
   = n - j

✔️ If both equal → valid palindrome

-----------------------------------------------------------
⚠️ WITHOUT THIS CHECK:

You may get:
✔ common substring
❌ but NOT palindrome

-----------------------------------------------------------
⏱ COMPLEXITY:

Time  : O(n^2)
Space : O(n^2)

-----------------------------------------------------------
🚨 IMPORTANT NOTE (INTERVIEW):

This method is tricky ❗

👉 Preferred approach:
   "Expand Around Center" (simpler & safer)

-----------------------------------------------------------
🧠 MEMORY TRICK:

"LCS substring + mirror check = palindrome"

===========================================================
*/

string lps(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();

    int max_len = 0;
    int end_idx = 0;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (s1[i - 1] == s2[j - 1]) {

                dp[i][j] = 1 + dp[i - 1][j - 1];

                // ✅ Check if substring is actually palindrome
                if (i - dp[i][j] == n - j) {

                    if (dp[i][j] > max_len) {
                        max_len = dp[i][j];
                        end_idx = i;
                    }
                }
            }
            else {
                dp[i][j] = 0; // substring must be continuous
            }
        }
    }

    return s1.substr(end_idx - max_len, max_len);
}

int main() {

    string str1 = "aacabdkacaa";

    string rev = str1;
    reverse(rev.begin(), rev.end());

    cout << "Longest Palindromic Substring: "
         << lps(str1, rev);

    return 0;
}