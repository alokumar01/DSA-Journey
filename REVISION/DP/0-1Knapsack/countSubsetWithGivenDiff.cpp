#include <iostream>
using namespace std;
#include <vector>
#include <numeric>

// Time Complexity
// O(N * SUM)

// Space Complexity
// O(N * SUM)

int countSubsetWithDiff(vector<int>& arr, int n, int sum) {
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 50; j <= sum; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int main() {
    // GIVEN
    vector<int> arr = {1, 1, 1, 1, 1};
    int diff = 3;


    int n = arr.size();
    int totalSum = accumulate(arr.begin(), arr.end(), 0);


    //1. edge case thinking
    if ((diff + totalSum) % 2 != 0) {
        cout << "Sum should not be odd";
        return 0;
    }

    int sum = (diff + totalSum) / 2;

    //2. edge case ---> when difference is greater than sum of array
    if (diff > totalSum)  {
        cout << "Difference number can't be greater than totalSum";
        return 0;
    }

    cout << "The total number of subset with given differences: " << countSubsetWithDiff(arr, n, sum);

    return 0;
}