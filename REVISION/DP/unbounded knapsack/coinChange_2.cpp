/*
QUESTION:
Given N types of coins and a target sum.
Each coin can be used UNLIMITED times (Unbounded Knapsack).

Find the MINIMUM number of coins required to make the given sum.

Example:
coins = {1,2,3}
sum = 5

Possible ways:
1+1+1+1+1 -> 5 coins
2+2+1     -> 3 coins
3+2       -> 2 coins  (minimum)

Output: 2
*/

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

/*
dp[i][j] = minimum number of coins required to make sum j using first i coins.

Dimensions:
rows -> coins
columns -> sum
*/

int unboundedKnap(vector<int>& coins, int sum, int n) {

    // Initialize DP table with a large value (infinity)
    // Because we are finding MINIMUM coins
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, INT_MAX - 1));

    /*
    BASE CASE

    If sum = 0 → we need 0 coins regardless of number of coins available
    */
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    /*
    Filling DP Table
    */
    for (int i = 1; i <= n; i++) {          // coins
        for (int j = 1; j <= sum; j++) {    // sum

            /*
            If current coin value is less than or equal to current sum
            then we have two choices
            */
            if (coins[i - 1] <= j) {

                /*
                OPTION 1: Take the coin

                If we take the coin:
                remaining sum = j - coin_value

                dp[i][j - coin] gives minimum coins needed for remaining sum.

                +1 because we used one coin now.
                */

                /*
                OPTION 2: Don't take the coin

                Move to previous coin
                dp[i-1][j]
                */

                // Take minimum of both options
                dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]);

            }
            else {

                /*
                If coin value is greater than current sum,
                we cannot take this coin.
                So we only skip it.
                */

                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Final answer: using all coins to make full sum
    return dp[n][sum];
}

int main() {

    vector<int> coins = {1, 2, 3};
    int sum = 5;

    int n = coins.size();

    int result = unboundedKnap(coins, sum, n);

    cout << "The minimum number of coins: " << result;

    return 0;
}