#include <iostream>
using namespace std;
#include <vector>
#include <cstring>
#include <numeric>

// Time Complexity
// O(n * sum)

// Space Complexity
// O(n * sum)

int dp[101][101];


// Memoization (TOP DOWN )
bool knapsackMemoization(vector<int>& arr, int half, int n) {
    if (half == 0) return true;
    if (n == 0) return false;

    if (dp[n][half] != -1) {
        return dp[n][half];
    }

    if (arr[n - 1] <= half) {
        dp[n][half] = knapsackMemoization(arr, half - arr[n - 1], n - 1) || knapsackMemoization(arr, half, n - 1);
    } else {
        dp[n][half] = knapsackMemoization(arr, half, n - 1);
    }

    return dp[n][half];
}

bool knapsackTabulation(vector<int>& arr, int half, int n) {
    vector<vector<bool>> dp(n + 1, vector<bool>(half + 1, false));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= half ; j++) {
            if (arr[i-1] <= j) {
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][half];
}

int main() {
    // Problem --> Equal Sum partition problem
    vector<int> arr = {1, 5, 11, 5};
    int n = arr.size();

    memset(dp, -1, sizeof(dp));

    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum % 2 != 0) {
        cout << "NO, ARRAY CAN'T DIVIDED INTO TWO PARTS--> SUM IS NOT EVEN" << endl;
        return 0;
    } else {
        if (knapsackTabulation(arr, sum / 2, n)) {
            cout << "YES, ARRAY CAN DIVIDED INTO TWO PARTS" << endl;
        } else {
            cout << "NO, ARRAY CAN'T DIVIDED INTO TWO PARTS" << endl;
        }
    }

    return 0;
}