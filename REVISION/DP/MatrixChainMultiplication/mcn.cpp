#include <iostream>
using namespace std;
#include <vector>
#include <climits>
#include <cstring>
/* MATRIX CHAIN MULTIPLICATION

| Approach    | Time    | Space | Notes               |
| ----------- | ------- | ----- | ------------------- |
| Recursion   | ❌ O(2ⁿ) | O(n)  | Very slow           |
| Memoization | ✅ O(n³) | O(n²) | Easy to write       |
| Tabulation  | ✅ O(n³) | O(n²) | Best for interviews |

🔥 How to Identify MCM Pattern

🎯 Core Signal of MCM Pattern
👉 “Partition the problem into two parts”

🔍 Ask yourself these questions:
✅ 1. Can I split the problem at every possible position?
for (k = i → j-1)

👉 BIG hint of MCM
✅ 2. Is the problem asking for:
Minimum cost
Maximum value
Number of ways

👉 AND involves splitting
✅ 3. Does answer depend on:
left part + right part + cost of combining

👉 EXACT MCM structure
🧠 General MCM Template
for (k = i; k < j; k++) {
    ans = min/max(
        solve(i, k) + solve(k+1, j) + cost(i, k, j)
    );
}

🔥 Real Problems Using MCM Pattern
Once you understand this, you can solve MANY problems:
📌 Classic ones:
Matrix Chain Multiplication ✅
Palindrome Partitioning
Boolean Parenthesization
Burst Balloons (hard but same idea)
Expression evaluation problems
🧠 How to Think (Golden Line)

👉 If question says:
“Try all ways to break / partition / divide the problem”
💥 → MCM Pattern
*/

// RECURSION
int mcnRecur(vector<int> &arr, int i, int j) {
    if (i >= j) return 0;
    
    int mn = INT_MAX;
    
    for(int k = i; k <= j - 1; k++) {
        int temAns = mcnRecur(arr, i, k) + mcnRecur(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        
        mn = min(mn, temAns);
    }
    
    return mn;
}

// MEMOIZATION (TOP DOWN)
int static dp[1001][1001];
int mcmMemoization(vector<int> &arr, int i, int j) {
    if (i >= j) return 0;

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int mn = INT_MAX;

    for(int k = i; k <= j - 1; k++) {
        int temAns = mcmMemoization(arr, i, k) + mcmMemoization(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        
        mn = min(mn, temAns);
    }

    return dp[i][j] = mn;
}

// BOTTOM UP APPROACH
int mcmTabulation(vector<int> &arr, int i, int j) {
    int n = arr.size();
    vector<vector<int>> dp(n , vector<int>(n, 0));

    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n-1];
}


int main() {
    vector<int> arr = {40, 20, 30, 10, 30};
    int st_idx = 1;
    int end_idx = arr.size() - 1;

    memset(dp, -1, sizeof(dp));

    cout << "value of mcn is: " << mcmTabulation(arr, st_idx, end_idx);

    return 0;
}