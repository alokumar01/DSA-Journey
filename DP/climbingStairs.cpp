#include <iostream>
using namespace std;
#include <vector>

// Recurson ways
// int countWaysRec(int n) {
//     if (n == 0 || n == 1) {
//         return 1;
//     }
//     return countWaysRec(n-1) + countWaysRec(n-2);
// }

// DP MEMOIZATION
// int countWaysMem(int n, vector<int> &dp) {
//     if (n == 0 || n == 1) {
//         return 1;
//     }

//     if(dp[n] != -1) {
//         return dp[n];
//     }
    
//     dp[n] =  countWaysMem(n-1, dp) + countWaysMem(n-2, dp);

//     return dp[n];
// }

/// DP TABULATION

// int countWaysTab(int n) {
//     vector<int> dp(n+1, 0);
//     dp[0] = 1;
//     dp[1] = 1;

//     for(int i=2; i<=n; i++) {
//         dp[i] = dp[i-1] + dp[i-2];
//     }

//     return dp[n];
// }

// Q three choice is ther 1, 2, 3 jumps allowed
// DP TABULATION
int countWaysTab(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i=3; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    
    return dp[n];
    
}

int main() {
    int n = 4;
    // cout << "ways = " << countWaysMem(n);
    vector<int> dp(n+1, -1);
    // cout << "ways (with DP MEMO) " << countWaysMem(n, dp);

    cout << "ways (DP with Tabluation ) " << countWaysTab(n);

    return 0;
}