#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

/*
Problem: Print Shortest Common Supersequence (SCS)

Given two strings s1 and s2,
return the shortest string such that both s1 and s2 are subsequences of it.

Example:
s1 = "abcdaf"
s2 = "acbcf"
One valid answer = "acbcdaf"

--------------------------------------------------
What should come to mind in an interview / exam?
--------------------------------------------------
Whenever the question says:
1. two strings
2. order of characters must stay same
3. combine both in minimum length

Think:
"This is LCS + reconstruction"

Why LCS?
Because the common part of both strings should be written only once.
That common part is the Longest Common Subsequence.

So idea is:
1. Build LCS DP table
2. Trace back from dp[n][m]
3. Construct the answer

--------------------------------------------------
Core idea behind printing SCS
--------------------------------------------------
If characters match:
- take that character only once
- move diagonally

If characters do not match:
- we must keep one of them in answer
- move in the direction that gave bigger LCS
- this helps us avoid losing a better common subsequence

At the end:
- if one string finishes early,
  append remaining characters of the other string

Important:
During traceback we build the string from back to front,
so reverse it at the end.

--------------------------------------------------
Complexity
--------------------------------------------------
Time Complexity  : O(n * m)
Space Complexity : O(n * m)

Why?
- DP table of size (n + 1) * (m + 1)
- filling table takes O(n * m)
- traceback takes O(n + m)
- overall still O(n * m)

--------------------------------------------------
Revision note
--------------------------------------------------
Length of SCS = n + m - LCS(s1, s2)

But in this problem we are not only finding length,
we are actually printing the full shortest common supersequence.
So we need traceback after building the LCS table.
*/

string superSeq(string &s1, string &s2, int n, int m) {
    // dp[i][j] = length of LCS of first i chars of s1 and first j chars of s2
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Build normal LCS table first
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] =  1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string res = "";
    int i = n, j = m;

    // Trace from bottom-right to build the SCS
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            // Same character in both strings -> write it once
            res.push_back(s1[i - 1]);
            i--;
            j--;
        } else {
            if (dp[i][j - 1] > dp[i - 1][j]) {
                // Moving left means s2[j - 1] is part of SCS now
                res.push_back(s2[j - 1]);
                j--;
            } else {
                // Moving up means s1[i - 1] is part of SCS now
                res.push_back(s1[i - 1]);
                i--;
            }
        }
    }

    // If s1 still has characters left, add them
    while (i > 0) {
        res.push_back(s1[i - 1]);
        i--;
    }

    // If s2 still has characters left, add them
    while (j > 0) {
        res.push_back(s2[j - 1]);
        j--;
    }

    // We built answer from back to front
    reverse(res.begin(), res.end());
    return res;
} 

int main() {
    string str1 = "abcdaf";
    string str2 = "acbcf";

    int n = str1.size();
    int m = str2.size();


    cout << "Shortest common supersequence: " << superSeq(str1, str2, n, m);

    return 0;
}
