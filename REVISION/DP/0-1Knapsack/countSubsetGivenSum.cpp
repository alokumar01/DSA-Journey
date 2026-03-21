#include <iostream>
using namespace std;
#include <vector>

//PROBLEM IS: Count number of subsets of a given sum
int countSubset(vector<int>&arr, int sum, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i<= n; i++) {
        for (int j = 1; j <= sum; j++) {
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
    vector<int> arr = {2, 3, 5, 6, 8, 10};
    int sum = 10;
    int n = arr.size();

    cout << "Total number of subsets: " << countSubset(arr, sum, n);

    return 0;
}
