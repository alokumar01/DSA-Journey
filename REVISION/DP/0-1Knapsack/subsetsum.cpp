#include <iostream>
using namespace std;
#include <vector>
#include <cstring>
//given array se ek subset jo sum ke equal ho sakta hai ki nahi, if yes return true, otherwise false;

int dp[6][12];

// TOP DOWN MEMOIZATION
bool subsetSum(int n, int sum, vector<int>& arr) {
    if (sum == 0) return true; //sum zero hua means subset mil gya 

    if (n == 0) return false; // this line means you have not any 

    if (dp[n][sum] != -1) {
        return dp[n][sum];
    }

    if (arr[n - 1] <= sum) {
        bool include = subsetSum(n - 1, sum - arr[n - 1], arr); 
        bool exclude = subsetSum(n - 1, sum, arr);

        dp[n][sum] = include || exclude;
    } else {
        dp[n][sum] = subsetSum(n - 1, sum, arr);
    }

    return dp[n][sum];
}

// BOTTOM UP TABULATION
bool subsetSumTabu(int n, int sum, vector<int>& arr) {
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    for(int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < sum + 1; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i-1][j - arr[i - 1]] || dp[i - 1][j]; // include OR exclude 
            } else {
                dp[i][j] = dp[i - 1][j]; //exclude
            }
        }
    }

    return dp[n][sum];
}

int main() {
    vector<int> arr = { 2, 3, 7, 8, 10};
    int n = arr.size();
    int sum = 11;

    // memset(dp, -1, sizeof(dp));    

    if (subsetSumTabu(n, sum, arr)) {
        cout << "YES, SUBSET EXISTS KARTA HAI";
    } else {
        cout << "NO, SUBSET EXISTS NAHI KARTA";
    }

    return 0;
}