#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <cstring>

// RECUSION 
// TC --> O(2 ^ (n + m));
// SC --> O(n + m);
int lcs(string &s1, string &s2, int n, int m) {
    // Base condition
    if (n == 0 || m == 0) {
        return 0;
    }

    if (s1[n - 1] == s2[m - 1]) {
        return 1 + lcs(s1, s2, n - 1, m - 1);
    } else {
        return max(lcs(s1, s2, n, m-1), lcs(s1, s2, n-1, m));
    }
}

// MEMOIZATION (TOP DOWN APPROACH)
// TC --> O(n * m);
// SC --> O(n + m);

int dp[101][101];

int lcsMemo(string &s1, string &s2, int n, int m) {
    if (n == 0 || m == 0) {
        return 0;
    }

    if (dp[n][m] != -1) {
        return dp[n][m];
    }

    if (s1[n - 1] == s2[m - 1]) {
        return 1 + lcs(s1, s2, n - 1, m - 1);
    } else {
        return max(lcs(s1, s2, n, m - 1), lcs(s1, s2, n - 1, m));
    }
}

// TABULATION (BOTTOM UP APPROACH)
// TC --> O(n * m);
// SC --> O(n + m);
int lcsTabu(string &s1, string &s2, int n, int m) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // initialization
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main() {
    string s1 = "abb";
    string s2 = "b";

    int n = s1.size();
    int m = s2.size();

    memset(dp, -1, sizeof(dp));

    cout << "longest common subsequence length: " <<  lcsTabu(s1, s2, n, m);

    return 0;
}