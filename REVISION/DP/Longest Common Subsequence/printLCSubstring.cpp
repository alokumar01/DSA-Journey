#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

string lcsTabu(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    int max_len = 0;
    int end_idx = 0;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++){
            if (s1[i - 1] == s2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (dp[i][j] > max_len) {
                    max_len = dp[i][j];
                    end_idx = i;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return s1.substr(end_idx - max_len, max_len);
}

int main()
{
    string str1 = "abcxfz";
    string str2 = "abcdef";

    string ans = lcsTabu(str1, str2);

    cout << "The longest common substring are: " << ans;

    return 0;
}