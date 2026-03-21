#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

// TC --> O(n * m)
// SC --> O(n * m);

string printLCS(string &s1, string& s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i- 1][j - 1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // Trace back 
    string result = "";
    int i = n, j = m;

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            result.push_back(s1[i - 1]); // 
            i--;
            j--;
        } else {
            if (dp[i - 1][j] > dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
    }

    reverse(result.begin(), result.end());
    return result;
}


int main() {
    string s1 = "ACBCF";
    string s2 = "ABCDF";

    cout << printLCS(s1, s2) << endl;

    return 0;
}