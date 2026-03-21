#include <iostream>
using namespace std;
#include <string>
#include <vector>

/*
THINKING STEPS:

1. I need to convert A → B
2. Only insert/delete allowed
3. What should remain same? → LCS
4. Remove extra from A → (n - LCS)
5. Add missing from B → (m - LCS)

FINAL:
Answer = (n - LCS) + (m - LCS)
*/

////// FULL EXPLANATION //////

/*
Problem: Minimum Insertions and Deletions to Convert String A to String B

Given two strings A and B,
find the minimum number of insertions and deletions required
to convert A into B.

Allowed operations:
1. Insert a character
2. Delete a character
*/


/*
Pattern: "Convert String A → B using Insert/Delete"

Whenever you see:
- Convert one string into another
- Only insertions and deletions allowed

Think:
1. Find LCS (Longest Common Subsequence)
2. Keep LCS as it is (common backbone)
3. Delete extra from A
4. Insert missing from B

Formula:
Deletions = n - LCS
Insertions = m - LCS

Total operations = (n - LCS) + (m - LCS)
*/
#include <iostream>
using namespace std;
#include <string>
#include <vector>

/*
Function to find LCS (Longest Common Subsequence)

dp[i][j] = LCS length of:  first i characters of s1   first j characters of s2
*/

int lcs(string &s1, string &s2, int n, int m) {
    // DP table initialization
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    /*
    Base Case:
    dp[0][j] = 0 → empty string vs anything = 0
    dp[i][0] = 0 → same logic
    */

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // If characters match → include in LCS
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                /*
                If not matching:
                skip one character (either from s1 or s2)
                and take best possible LCS
                */
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Final LCS length
    return dp[n][m];
}

int main() {
    // Input strings
    string A = "heap";
    string B = "pea";

    int n = A.size(), m = B.size();

    // Step 1: Find LCS
    int result = lcs(A, B, n, m);

    /*
    Step 2: Apply formula
    Deletions = n - LCS
    Insertions = m - LCS
    Total operations = deletions + insertions
    */

    cout << "Minimum no of Insertion & Deletion: " << n - result + m - result << endl;

    return 0;
}