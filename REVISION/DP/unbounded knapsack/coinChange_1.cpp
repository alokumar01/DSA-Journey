#include <iostream>
using namespace std;
#include <vector>

// This function calculates number of ways to make 'sum'
// using given coins (each coin can be used unlimited times)
int unboundedKnapsack(vector<int>& coins, int sum, int n) {

    // dp[i][j] = number of ways to make sum j using first i coins
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    // Base Case:
    // Sum = 0 can always be made by taking no coins
    // So there is exactly 1 way
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // Build the DP table
    for (int i = 1; i <= n; i++) {         // iterate over coins
        for (int j = 1; j <= sum; j++) {   // iterate over possible sums

            // If current coin value is less than or equal to current sum
            if (coins[i - 1] <= j) {

                // Two choices:
                // 1. Exclude the coin -> move to previous coin
                // 2. Include the coin -> stay on same row (unbounded use)
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];

            } else {

                // If coin value is bigger than current sum
                // we cannot include it, so only option is exclude
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Final answer: using all coins to make full sum
    return dp[n][sum];
}

int main() {

    // Available coins
    vector<int> coins = {1, 2, 3};

    // Target sum
    int sum = 4;

    int n = coins.size();

    // Calculate number of ways
    int result = unboundedKnapsack(coins, sum, n);

    cout << "The number of ways to make the sum: " << result;

    return 0;
}