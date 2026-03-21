#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <cstring>

// TABULATION (BOTTOM UP APPROACH)
// TC --> O(n * m);
// SC --> O(n + m);
int lcsTabu(string &s1, string &s2, int n, int m) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int max_len = 0;

    // initialization
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         if (i == 0 || j == 0) {
    //             dp[i][j] = 0;
    //         }
    //     }
    // }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                max_len = max(max_len, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return max_len;
}

int main() {
    string s1 = "abcxfz";
    string s2 = "abcdef";

    int n = s1.size();
    int m = s2.size();

    cout << "longest common substring length: " <<  lcsTabu(s1, s2, n, m);

    return 0;
}