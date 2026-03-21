#include <iostream>
using namespace std;
#include <vector>
#include<cstring>

// int dp[101][101]; 
vector<vector<int>> dp;

// RECURSION APPROACH (2 ^ N);
int knapsack(vector<int>&weight, vector<int>&value, int W, int n) {
    // base conditions
    if (n == 0 || W == 0 ) {
        return 0;
    }

    if (weight[n - 1] <= W) {
        int include = value[n - 1] + knapsack(weight, value, W - weight[n - 1], n - 1);
        int exclude = knapsack(weight, value, W, n - 1);
        
        return max(include, exclude);
    } else { // matlab bag ka capacity se jyda ho gya if ek item ka weight -----(weight[n - 1] > W)
        return knapsack(weight, value, W, n - 1);
    }
}

// MEMOIZATOIN APPROACH (TOP DOWN TECHNIQUE)
int knapsackMemo(vector<int>&weight, vector<int>&value, int W, int n) {
    // base conditions
    if (n == 0 || W == 0 ) {
        return 0;
    }

    if (dp[n][W] != -1) {
        return dp[n][W];
    }

    if (weight[n - 1] <= W) {
        int include = value[n - 1] + knapsack(weight, value, W - weight[n - 1], n - 1);
        int exclude = knapsack(weight, value, W, n - 1);
        
        dp[n][W] =  max(include, exclude);
    } else { // matlab bag ka capacity se jyda ho gya if ek item ka weight -----(weight[n - 1] > W)
        dp[n][W] =  knapsack(weight, value, W, n - 1);
    }

    return dp[n][W];
}

// TABULATION APPROACH (BOTTOM UP TECHNIQUE)
int knapsackTabulation(vector<int>&weight, vector<int>&value, int W, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i < n + 1; i++) { // where i is n and j is W
        for (int j = 1; j < W + 1; j++) {
            if (weight[i-1] <= j) {
                dp[i][j] = max(value[i-1] + dp[i-1][j - weight[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j]; 
            }
        }
    }

    for(int i = 0; i < n + 1; i++) {
        for (int j = 0; j < W+1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[n][W];
}

int main() {
    vector<int> weight = {1, 3, 4, 5};
    vector<int> value = {1, 4, 5, 7};
    int W = 7;
    int n = weight.size();

    // memset(dp, -1, sizeof(dp));

    // int result = knapsackMemo(weight, value, W, n);
    int result = knapsackTabulation(weight, value, W, n);
    cout << "The maximum profit: " << result;

    return 0;
}