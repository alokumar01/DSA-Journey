#include <iostream>
using namespace std;
#include <vector>
#include<algorithm>

int unboundKnapsack(vector<int>val, vector<int> wt, int W, int n ) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<W+1; j++) {
            int itemWt = wt[i-1];
            int itemVal = val[i-1];

            if (itemWt <= j) {
                dp[i][j] = max(itemVal + dp[i][j - itemWt], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}

int main() {
    vector<int>val = {15, 14, 10, 45, 30};
    vector<int>wt = {2, 5, 1, 3, 4};
    int W = 7;
    int n = 5;
    cout << unboundKnapsack(val, wt, W, n) << endl;

    return 0;
}