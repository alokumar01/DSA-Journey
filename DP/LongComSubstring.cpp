#include <iostream>
using namespace std;
#include <vector>
#include <string>

// longest common substring using dp(tabulation)
int longComSubstring(string str1, string str2) { // O(n*m)
    int n = str1.size();
    int m = str2.size();
    int ans = 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            // yes wala condition means match kar gya last wala 
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = 0;
            }

            ans = max(ans, dp[i][j]);
        }
    }
    
    return ans;
}

int main() {
    string str1 = "abcdge";
    string str2 = "abcdee";
    cout << longComSubstring(str1, str2) << endl;
    return 0;
}