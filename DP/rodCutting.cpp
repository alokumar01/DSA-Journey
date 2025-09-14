#include <iostream>
using namespace std;
#include<vector>

int rodCutting(vector<int> &prices, vector<int> &length, int rodLen, int n) {
    vector<vector<int>> dp(n+1, vector<int>(rodLen+1, 0));

    for(int i=0; i<rodLen+1; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i < n+1; i++) { // i as item
        for (int j = 1; j<rodLen+1; j++) { // j at rodLength
            if (length[i-1] <= j) {
                dp[i][j] = max(dp[i][j - length[i-1]] + prices[i-1] , dp[i-1][j] );
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][rodLen];
}

int main() {
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8};
    int rodLen = 8;
    int n = prices.size();

    cout <<  rodCutting(prices, length, rodLen, n);

    return 0;
}