#include <iostream>
using namespace std;
#include <vector>
#include <numeric>
#include <climits>
// PROBLEM IS: minimum subset sum difference.
//TIME COMPLEXITY: O(n * range);
//SPACE COMPLEXITY: O(n * range);

vector<vector<bool>> subsetSumDp(int n, int range, vector<int>& arr) {
    vector<vector<bool>> dp(n + 1, vector<bool>(range + 1, false));

    for(int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= range; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp;
}

int minSubsetDiff(vector<int>& arr) {
    int n = arr.size();
    int range = accumulate(arr.begin(), arr.end(), 0);

    auto dp = subsetSumDp(n, range, arr);

    int min_val = INT_MAX;

    for (int j = 0; j <= range / 2; j++) {
        if (dp[n][j])
            min_val = min(min_val, range - 2 * j);
    }

    return min_val;
}   

int main() {
    vector<int> arr = { 1, 2, 7};
    cout << "minimum subset sum difference: " << minSubsetDiff(arr);
    return 0;
}


// NOW THIS CASE IS WHEN ELEMENTS OF ARRAY IS NEGATIVE

// When negative numbers appear, the beginner DP way is to use an OFFSET.
// You just shift the DP indices so negative sums become positive indices.



// 1️⃣ Step 1 — Find minSum and maxSum

// Add this before DP creation.

// int minSum = 0, maxSum = 0;
// for (int x : arr) {
//     if (x < 0) minSum += x;
//     else maxSum += x;
// }

// Example:

// arr = {3, -2, 5}
// minSum = -2
// maxSum = 8

// Possible sums range:

// [-2 ... 8]
// 2️⃣ Step 2 — Create OFFSET
// int offset = -minSum;

// Example:

// offset = 2

// Now mapping:

// sum -2 → index 0
// sum 0  → index 2
// sum 5  → index 7

// 3️⃣ Step 3 — Resize DP table

// Replace:

// vector<vector<bool>> dp(n+1, vector<bool>(range+1,false));

// with

// int width = maxSum - minSum + 1;

// vector<vector<bool>> dp(n+1, vector<bool>(width,false));
// 4️⃣ Step 4 — Initialize sum = 0
// dp[0][offset] = true;

// Because:

// index of sum 0 = offset
// 5️⃣ Step 5 — DP Transition

// Modify loops:

// for(int i = 1; i <= n; i++) {
//     for(int s = minSum; s <= maxSum; s++) {

//         if(dp[i-1][s + offset]) {

//             dp[i][s + offset] = true;

//             int newSum = s + arr[i-1];

//             if(newSum >= minSum && newSum <= maxSum)
//                 dp[i][newSum + offset] = true;
//         }
//     }
// }

// 6 Step 6 — Compute answer
// int total = accumulate(arr.begin(), arr.end(), 0);
// int ans = INT_MAX;

// for(int s = minSum; s <= maxSum; s++) {
//     if(dp[n][s + offset])
//         ans = min(ans, abs(total - 2*s));
// }
// Complexity

// Still:

// Time  = O(n * (maxSum - minSum))
// Space = O(n * (maxSum - minSum))

// Same DP logic, just shifted indices.

// Key Idea (Important)

// Normal subset DP works only for:

// 0 → sum

// With negatives we must allow:

// minSum → maxSum

// So we shift indices using OFFSET.

// ✅ Beginner DP rule

// If negatives appear in subset-sum problems:

// 1️⃣ find minSum and maxSum
// 2️⃣ create offset = -minSum
// 3️⃣ index = sum + offset