#include <iostream>
using namespace std;
#include <vector>
#include <string>

/*
Problem: Shortest Common Supersequence (Length)

Given two strings s1 and s2,
find the length of the shortest string that contains both s1 and s2 as subsequences.

Key Idea:
SCS = combine both strings without repeating common parts

Formula:
SCS length = n + m - LCS(s1, s2)
*/

/*
Pattern: "Two Strings + Minimum Merge + Order Preserved"

Whenever you see:
- Two strings
- Need shortest/longest merge
- Order must be preserved

Think:
1. Find LCS (Longest Common Subsequence)
2. Use formula:
   Answer = n + m - LCS

Why?
Because LCS is the common part → we should not repeat it
*/
#include <iostream>
using namespace std;
#include <vector>
#include <string>

// TC --> O(n * m)
// SC --> O(n * m)

int superSequence(string &s1, string &s2) {
    int n = s1.size();   // length of first string
    int m = s2.size();   // length of second string

    /*
    dp[i][j] = length of LCS of:
        first i characters of s1
        first j characters of s2
    */
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    /*
    Base Case:
    dp[0][j] = 0 → if s1 is empty, no common subsequence
    dp[i][0] = 0 → if s2 is empty, no common subsequence
    (already initialized with 0)
    */

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            // If characters match → include in LCS
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                /*
                If not match:
                we have 2 choices:
                1. skip character from s1
                2. skip character from s2

                take max (best LCS possible)
                */
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // This gives LCS length
    return dp[n][m];
}

int main() {
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";
    
    int n = str1.size();
    int m = str2.size();

    /* Total length if we combine both strings blindly */
    int totalLen = n + m;

    /*
    Subtract LCS because common characters
    should not be counted twice
    */
    cout << "Total length of superSequence: " << totalLen - superSequence(str1, str2);
}