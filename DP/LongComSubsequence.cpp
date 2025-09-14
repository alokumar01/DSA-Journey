#include <iostream>
using namespace std;
#include<vector>
#include <string>

// this is with recursion
int lcsRec(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();

    if (n == 0 || m == 0) return 0;

    if(str1[n-1] == str2[m-1]) {
        return 1 + lcsRec(str1.substr(0, n-1), str2.substr(0, m-1));
    } else {
        int ans1 = lcsRec(str1.substr(0, n-1), str2);
        int ans2 = lcsRec(str1, str2.substr(0, m-1));
        return max(ans1, ans2);
    }
}

// this is using memoization
int lcsMemo(string str1, string str2, vector<vector<int>> &dp)
{
    // USING MEMOIZATION, BUT GIVES MEMORY LIMIT EXCEED
    int n = str1.size(), m = str2.size();
    if (n == 0 || m == 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (str1[n - 1] == str2[m - 1])
    { // last char both are equal
        dp[n][m] = 1 + lcsMemo(str1.substr(0, n - 1), str2.substr(0, m - 1), dp);
    }
    else
    {                                                        // last char not equal but two conditions
        int ans1 = lcsMemo(str1.substr(0, n - 1), str2, dp); // we move str1, and keep str2 same
        int ans2 = lcsMemo(str1, str2.substr(0, m - 1), dp); // we move str2, and keep str1 same
        dp[n][m] = max(ans1, ans2);                          // then here we take max of both
    }

    return dp[n][m];
}


// this is using tabulatoin
int lcsTab(string str1, string str2)
{
    // USING TABULATION, TC - O(n*m)
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}
int main() {
    string str1 = "acb";
    string str2 = "adbecujy";

    cout << lcsRec(str1, str2) << endl;

    return 0;
}