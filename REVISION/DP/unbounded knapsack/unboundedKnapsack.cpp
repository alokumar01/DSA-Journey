#include <iostream>
using namespace std;
#include <vector>
#include <cstring>
// UNBOUNDED KNAPSACK 
// How do you recognize Unbounded Knapsack?”
// Look for
// Unlimited items allowed
// Pick same item again





// RECURSION
// TC --> O(2 ^(n + W))
//SC --> O(n + w);
int unboundedKnapsack(vector<int>& weight, vector<int>& value, int n, int W) {
    if (n == 0 || W == 0) return 0;

    if (weight[n -1] <= W) {
        return max( value[n - 1] + unboundedKnapsack(weight, value, n, W - weight[n - 1]), // pick multiple times
            unboundedKnapsack(weight, value, n - 1, W)
        );
    } else {
        return unboundedKnapsack(weight, value, n - 1, W);
    }
}

// MEMOIZATION TOP DOWN APPROACH
// TC --> O(n * W);
// SC --> O(n * W);
int dp[101][101];
int unboundedKnapMemo(vector<int>& weight, vector<int>& value, int n, int W) {
    if (n == 0 || W == 0) return 0;

    if (dp[n][W] != -1) { // memoization 
        return dp[n][W];
    }

    if (weight[n - 1] <= W) {
        dp[n][W] =  max(value[n - 1] + unboundedKnapMemo(weight, value, n, W - weight[n - 1]), unboundedKnapMemo(weight, value, n - 1, W));
    } else {
        dp[n][W] = unboundedKnapMemo(weight, value, n - 1, W);
    }

    return dp[n][W]; 
}

// TABULATION BOTTOM UP APPROACH
// TC --> O(n * W);
// SC --> O(n * W);

int unboundedKnapTabu(vector<int>& weight, vector<int>& value, int n, int W) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (weight[i - 1] <= j) {
                dp[i][j] = max(value[i - 1]+ dp[i][j - weight[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][W];
}

int main() {
    vector<int> weight = {1, 3, 4, 5};
    vector<int> value = {1, 4, 5, 7};
    int W = 7;
    int n = weight.size();

    memset(dp, -1, sizeof(dp));

    int result = unboundedKnapTabu(weight, value, n, W);

    cout << "Maximum profit value: " << result;

    return 0;
}